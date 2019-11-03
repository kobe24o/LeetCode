class Solution {
public:
    int kInversePairs(int n, int k) {
        //f(i,j)表示i个数，j个逆序对的组合方式
        //f(i, j) = f(i - 1, j) + f(i - 1, j - 1) + ... + f(i - 1, j - i + 1)
        int dp[n+1][k+1] = {0};
        int i, j, time, idx;
        for(i = 1; i <= n; i++)
        	dp[i][0] = 1;
        for(i = 2; i <= n; i++)
        {
        	for(j = 1; j <= k; j++)
        	{
        		time = i;
        		idx = j;
        		while(time-- && idx >= 0)
        		{
        			dp[i][j] += dp[i-1][idx];
        			dp[i][j] %= 1000000007;
        			idx--;
        		}
        	}
        }
        return dp[n][k];
    }
};

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[n+1][k+1] = {0};
        int i, j, maxk, M = 1000000007;
        for(i = 1; i <= n; i++)
        	dp[i][0] = 1;
        for(i = 2; i <= n; i++)
        {
        	maxk = i*(i-1)/2;//最大的逆序数
        	for(j = 1; j <= k && j <= maxk; j++)
        	{
    			dp[i][j] = dp[i][j-1]%M+(M+dp[i-1][j]-(j>=i ? dp[i-1][j-i]:0))%M;
    			dp[i][j] %= M;
        	}
        }
        return dp[n][k];
    }
};