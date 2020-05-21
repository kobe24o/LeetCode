struct state
{
    int one, zero;
    state(int x, int y)
    {
        zero = x; one = y;
    }
};
class Solution {    //超时解
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i, j, k, l, one, zero, len = strs.size(), maxcount = 0;
        int z, o;
        vector<int> onelen(len);
        for(i = 0; i < len; ++i)
            onelen[i] = count01(strs[i]);
        vector<vector<vector<state>>> dp(len+1,vector<vector<state>>(len+1,vector<state>()));//0个单词时，m,n = 0
        dp[0][0].push_back(state(0,0));
        //dp[i][j]表示遍历到第i个单词，装进来了j个的情况下，满足条件的较小的m,n使用个数
        bool can;
        for(i = 1; i <= len; ++i)//遍历每个单词
        {
            dp[i] = dp[i-1];//第i个单词不拿,复制上一行的状态下来
            one = onelen[i-1];
            zero = strs[i-1].size()-one;
            for(j = 0; j < len; ++j)
            {
                for(k = 0; k < dp[i-1][j].size(); ++k)
                {
                    z = dp[i-1][j][k].zero;//累积的0
                    o = dp[i-1][j][k].one;
                    if(z+zero <= m && o+one <= n)
                    {
                        can = true;
                        for(l = 0; l < dp[i][j+1].size(); ++l)
                        { 
                            if(z+zero <= dp[i][j+1][l].zero && o+one <= dp[i][j+1][l].one)
                            {
                                dp[i][j+1].erase(dp[i][j+1].begin()+l);
                                l--;
                            }
                            else if(z+zero > dp[i][j+1][l].zero && o+one > dp[i][j+1][l].one)
                            {
                                can = false;
                                break;
                            }
                        }
                        if(can)
                        {
                            dp[i][j+1].push_back(state(z+zero, o+one));
                            maxcount = max(maxcount, j+1);
                            if(maxcount == len)
                                return maxcount;
                        }
                    }
                }
            }
        }
        return maxcount;
        
    }
    int count01(string s)
    {
        int one = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i]=='1') one++;
        }
        return one;
    }
};


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int i, j, k, one, zero, len = strs.size(), maxcount = 0;
        vector<int> onelen(len);
        for(i = 0; i < len; ++i)
            onelen[i] = count01(strs[i]);
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));//m,n,时，对应的最大单词数
        dp[0][0] = 0;
        for(i = 0; i < len; ++i)//遍历每个单词
        {
            one = onelen[i];
            zero = strs[i].size()-one;
            for(j = m-zero; j >= 0; --j)
            {
                for(k = n-one; k >= 0; --k)
                {
                    if(dp[j][k] != -1)
                    {
                        dp[j+zero][k+one] = max(dp[j+zero][k+one], dp[j][k]+1);
                        maxcount = max(maxcount, dp[j+zero][k+one]);
                    }
                }
            }
        }
        return maxcount;    
    }
    int count01(string s)
    {
        int one = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i]=='1') one++;
        }
        return one;
    }
};