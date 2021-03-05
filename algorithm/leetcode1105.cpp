class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            int w = 0, h = 0;
            for(int j = i; j > 0; --j)
            {
                if(w+books[j-1][0] <= shelf_width)
                {
                    h = max(h, books[j-1][1]);
                    w += books[j-1][0];
                    dp[i] = min(dp[j-1]+h, dp[i]);
                }
                else
                    break;
            }
        }
        return dp[n];
    }
};