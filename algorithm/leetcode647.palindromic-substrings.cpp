class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() <= 1)
            return s.size();
        int i, j, len, n = s.size(), count = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            if(i < n-1 && s[i]==s[i+1])
            {
                dp[i][i+1] = true;
                count++;
            }
        }
        for(len = 1; len < n; ++len)
        {
            for(i = 0; i < n-len; ++i)
            {
                if(dp[i][i+len-1] && i-1>=0 && s[i-1]==s[i+len])//是回文串
                {
                    dp[i-1][i+len] = true;
                    count++;
                }
            }
        }
        return count;
    }
};