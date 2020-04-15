class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& mat) {
    	if(mat.size()==0 || mat[0].size() == 0)
    		return {};
    	int m = mat.size(), n = mat[0].size(), i, j, k;
    	vector<vector<int>> sumof0Up(m, vector<int>(n,0));//向上连续0个数
    	vector<vector<int>> sumof0Left(m, vector<int>(n,0));//向左连续0个数
    	for(i = 0; i < m; i++)
    	{
    		for(j = 0; j < n; j++)
    		{
    			if(mat[i][j] == 0)
    			{
    				if(i==0 && j==0)
    					sumof0Left[i][j] = 1, sumof0Up[i][j] = 1;
    				else if(i==0 && j>0)
    				{
    					sumof0Left[i][j] = sumof0Left[i][j-1]+1;
    					sumof0Up[i][j] = 1;
    				}
    				else if(j==0 && i > 0)
    				{
    					sumof0Left[i][j] = 1;
    					sumof0Up[i][j] = sumof0Up[i-1][j]+1;
    				}
    				else
    				{
    					sumof0Left[i][j] = sumof0Left[i][j-1]+1;
    					sumof0Up[i][j] = sumof0Up[i-1][j]+1;
    				}
    			}
    		}
    	}
    	vector<int> ans(3,-1);
    	int edge, x, y;
    	for(i = m-1; i >= 0; i--)
    	{
    		for(j = n-1; j >= 0; --j)
    		{
    			edge = min(sumof0Up[i][j], sumof0Left[i][j]);
    			while(edge > 0)
    			{
    				if(ans[2] > edge)//肯定小，不必检查了
    					break;
    				x = i-edge+1;
    				y = j-edge+1;
    				if(sumof0Up[i][y]>=edge && sumof0Left[x][j]>=edge)
    				{
    					if(edge > ans[2])
    					{
    						ans[2] = edge;
    						ans[0] = x;
    						ans[1] = y;
    					}
    					else if(edge == ans[2] && x <= ans[0])
    					{
    						if(x < ans[0])
    						{
    							ans[0] = x;
    							ans[1] = y;
    						}
    						else if(x == ans[0] && y < ans[1])
    							ans[1] = y;
    					}
    				}
                    edge--;
    			}
    		}
    	}
        if(ans[0]==-1)
            return {};
    	return ans;
    }
};