class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n <= 0) return {""};
        if(n==1) return {"0","1","8"};
        vector<vector<string>> dp(n+1);
        dp[1] = {"0","1","8"};
        dp[2] = {"11","69","88","96"};
        vector<string> add1 = {"0","1","8"};
        vector<string> add2 = {"00","11","69","88","96"};
        string num;
        for(int i = 3, j,k,h; i <= n; ++i)
        {
            if(i&1)//奇数,我们在i-1偶数的基础上每个数中间位置add1
            {
                for(j = 0; j < dp[i-1].size(); j++)
                {
                    num = dp[i-1][j];
                    h = num.size()/2;
                    for(k = 0; k < 3; k++)
                    {
                        dp[i].push_back(num.substr(0,h)+add1[k]+num.substr(h));
                    }
                }
            }
            else//i是偶数，我们在i-2偶数基础上每个数中间位置add2
            {
                for(j = 0; j < dp[i-2].size(); j++)
                {
                    num = dp[i-2][j];
                    h = num.size()/2;
                    for(k = 0; k < 5; k++)
                    {
                        dp[i].push_back(num.substr(0,h)+add2[k]+num.substr(h));
                    }
                }
            }
        }
        return dp[n];
    }
};