class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    	int dp[100][100];// 在 i 城市时， 是第 k 周， 最多休假天数
    	memset(dp, 0xff, sizeof(dp));
        int n = flights.size(), k = days[0].size(), maxdays = 0;
    	for(int i = 0; i < n; ++i)
    	{
            //可以待在原地不走
    		flights[i][i] = 1;
    	}    	
    	for(int i = 0; i < n; ++i)//初始化第0周
    	{
    		if(flights[0][i])//0城市可以飞到i城市
    		{
                dp[i][0] = days[i][0];
                maxdays = max(maxdays, dp[i][0]);
            }
    	}
    	for(int wk = 1; wk < k; ++wk)//遍历剩余的周
    	{
    		for(int i = 0; i < n; ++i)//遍历每个城市
    		{
    			if(dp[i][wk-1] == -1)//上周i城市的状态不存在
    				continue;
    			for(int j = 0; j < n; ++j)//我要去 j 城市
    			{
    				if(!flights[i][j])//没有航班，不行
    					continue;
    				dp[j][wk] = max(dp[j][wk], dp[i][wk-1]+days[j][wk]);
                    maxdays = max(maxdays, dp[j][wk]);
    			}
    		}
    	}
    	return maxdays;
    }
};