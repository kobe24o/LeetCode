class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return 1;
    }
};
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       	int i, j, n = piles.size();
       	vector<vector<int>> dp(n,vector<int>(n,0));
       	for(i = 0; i < n; ++i)
       		dp[i][i] = piles[i];
       	//dp[i][j]表示区间[i,j]石子，Alice能拿到的分
       	for(int len = 1; len < n; ++len)//划分取小的区间长度len
       	{
       		for(i = 0; i < n-len; ++i)
       		{
       			dp[i][i+len] = max(piles[i]-dp[i+1][i+len], piles[i+len]-dp[i][i+len-1]);
       		}
       	}
       	return dp[0][n-1] > 0;
    }
};