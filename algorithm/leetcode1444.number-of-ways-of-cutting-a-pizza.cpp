class Solution {
public:
    int ways(vector<string>& pizza, int k) {
    	int m = pizza.size(), n = pizza[0].size(), i, j, sum = 0;
    	vector<vector<int>> app(m,vector<int>(n,0));
    	for(i = 0; i < n; ++i)
    	{
    		if(pizza[0][i]=='A')
    			sum++;
    		app[0][i] = sum;
    	}
    	sum = 0;
    	for(i = 0; i < m; ++i)
    	{
    		if(pizza[i][0]=='A')
    			sum++;
    		app[i][0] = sum;
    	}
    	for(i = 1; i < m; ++i)
    	{
    		for(j = 1; j < n; ++j)
    		{
    			app[i][j] = (pizza[i][j]=='A'? 1 : 0) +app[i-1][j]+app[i][j-1]-app[i-1][j-1];
    		}
    	}//求得以i,j为左下角的矩形中的苹果数量

    	vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k,0)));
    	//dp[i][j][k]表示切完k次后，剩余蛋糕左上角 在i,j位置时的方案数
    	dp[0][0][0] = 1;
    	int ni, nj, appcount;//下一个转移状态的位置
    	for(int cut = 1; cut < k; ++cut)
	    	for(i = 0; i < m; ++i)
	    	{
	    		for(j = 0; j < n; ++j)
	    		{
	    			if(dp[i][j][cut-1] != 0)//上一次cut完后，剩余蛋糕左上角在i,j
	    			{
	    				for(ni = i+1; ni < m; ++ni)
	    				{	//横向切，切完后的剩余左上角为 ni, j
                            appcount = app[ni-1][n-1]-(j>0 ? app[ni-1][j-1]:0)-(i>0?app[i-1][n-1]:0)+(i>0&&j>0 ? app[i-1][j-1] : 0);
	    					if(appcount != 0)
	    						dp[ni][j][cut] = (dp[ni][j][cut]+dp[i][j][cut-1])%1000000007;
	    				}
	    				for(nj = j+1; nj < n; ++nj)
	    				{	//竖向切
                            appcount = app[m-1][nj-1]-(i>0?app[i-1][nj-1]:0)-(j>0?app[m-1][j-1]:0)+(i>0&&j>0 ? app[i-1][j-1] : 0);
	    					if(appcount != 0)
	    						dp[i][nj][cut] = (dp[i][nj][cut]+dp[i][j][cut-1])%1000000007;
	    				}
	    			}
	    		}
	    	}
    	sum = 0;
    	for(i = 0; i < m; ++i)
    		for(j = 0; j < n; ++j)
            {
                appcount = app[m-1][n-1]-(j>0?app[m-1][j-1]:0)-(i>0?app[i-1][n-1]:0)+(i>0&&j>0 ? app[i-1][j-1]:0);
                if(appcount != 0)
    			    sum = (sum+dp[i][j][k-1])%1000000007;
            }
		return sum;
    }
};