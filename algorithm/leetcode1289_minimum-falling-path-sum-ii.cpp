class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        if(n == 1)//一列，不满足题目要求
        	return 0;
        vector<int> dp(arr[0]);//存储到达每一行的最小路径和，第一行初始为arr数值
        vector<int> temp(n,INT_MAX);
        int i, j, k, MIN = INT_MAX;
        for(i = 1; i < m; i++)//从第2行开始
        {
        	for(j = 0; j < n; j++)
        		temp[j] = INT_MAX;//临时存储最小路径和，初始化为INT_MAX
        	for(j = 0; j < n; j++)//对上一行的每个dp[j] 计算下一行的 dp值
        	{       		
        		for(k = 0; k < n; k++)
        		{
        			if(k == j)//不同列的要求
        				continue;
        			temp[k] = min(temp[k], dp[j]+arr[i][k]);
        			//第j列可以选择下一行的 k列作为路径
        		}     		
        	}

        	for(j = 0; j < n; j++)
        		dp[j] = temp[j];//临时值存入dp中，状态压缩
        }
        for(i = 0; i < n; i++)
        	if(dp[i] < MIN)
        		MIN = dp[i];//取最后一行的最小值
    	return MIN;
    }
};