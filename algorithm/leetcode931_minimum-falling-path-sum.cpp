class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int N = A.size();
        vector<vector<int>> dp(N,vector<int>(N+2,INT_MAX));
        int i, j, minSum = INT_MAX;
        for(i = 0; i < N; i++) 
        	dp[0][i+1] = A[0][i];//初始化第一行
        for(i = 1; i < N; ++i)
        {
        	for(j = 1; j < N+1; ++j)
        	{
        		dp[i][j] = A[i][j-1]+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
        	}
        }
        for(i = 1; i < N+1; ++i)
        	minSum = min(minSum,dp[N-1][i]);
        return minSum;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int N = A.size();
        vector<int> dp(N+2,INT_MAX);
        vector<int> temp(N+2,INT_MAX);
        int i, j, minSum = INT_MAX;
        for(i = 0; i < N; i++) 
            temp[i+1] = A[0][i];//初始化第一行
        for(i = 1; i < N; ++i)
        {
            for(j = 1; j < N+1; ++j)
            {   //注意加了两列后下标的错位
                dp[j] = A[i][j-1]+min(min(temp[j-1],temp[j]),temp[j+1]);
            }
            swap(dp,temp);
        }
        return *min_element(temp.begin(),temp.end());
    }
};