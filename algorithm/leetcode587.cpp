class Solution {    //记忆化递归
    unordered_map<string,unordered_map<string,bool>> m;
public:
    bool isScramble(string s1, string s2) {
        if(m.count(s1) && m[s1].count(s2))
            return m[s1][s2];
        if(s1 == s2) return m[s1][s2]=true;
        for(int len = 1; len < s1.size(); ++len)
        {
            string s1a = s1.substr(0,len), s1b = s1.substr(len);
            string s2a = s2.substr(0,len), s2b = s2.substr(len);
            string s2a_ = s2.substr(0,s2.size()-len), s2b_ = s2.substr(s2.size()-len);
            if(isScramble(s1a, s2a) && isScramble(s1b, s2b))
                return m[s1][s2] = true;
            if(isScramble(s1a, s2b_) && isScramble(s1b, s2a_))
                return m[s1][s2] = true;
        }
        return m[s1][s2] = false;
    }
};

class Solution {    //DP
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(n, vector<bool>(n, false)));
        // dp[len][i][j] 表示 长度为 len  s1开始位置为i, s2 开始位置为 j，是否可以互相表示
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        for(int len = 2; len <= n; ++len)
        {
            for(int i = 0; i+len-1 < n; i++)
            {
                for(int j = 0; j+len-1 < n; j++)
                {
                    for(int k = 1; k < len; ++k)
                    {
                        if(dp[k][i][j] && dp[len-k][i+k][j+k])
                        {
                            dp[len][i][j] = true;
                            break;
                        }
                        if(dp[k][i][j+len-k] && dp[len-k][i+k][j])
                        {
                            dp[len][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};