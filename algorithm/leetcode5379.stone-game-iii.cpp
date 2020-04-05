class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int i, n = stoneValue.size(), sum = 0;
        vector<int> dp(n+3,0);
        for(i = n-1; i >= 0; --i)
        {
            sum += stoneValue[i];
            dp[i] = max(max(sum-dp[i+3], sum-dp[i+2]),sum-dp[i+1]);
        }
        if(dp[0] > sum-dp[0])
            return "Alice";
        else if(dp[0] < sum-dp[0])
            return "Bob";
        return "Tie";
    }
};