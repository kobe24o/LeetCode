class Solution {
public:
    int numDecodings(string s) {
        int i, n = s.size();
        vector<int> dp(n,0);
        if(s[0]=='0') return 0;//首位不能是0
        if(n==1) return 1;
        dp[0] = 1;
        if(s[0]=='1')
        {
            if(s[1]=='0') dp[1]=1;//10，1种可能
            else dp[1]=2;//1?，2种可能
        }
        else if(s[0]=='2')
        {
            if(s[1]>'0' && s[1]<='6') dp[1]=2;//21-26，2种可能
            else dp[1]=1;//20,27-29，1种可能
        }
        else//3-9
        {
            if(s[1]!='0')
            	dp[1]=1;//31-39,1种可能
        }
        for(i = 2; i < n; ++i)
        {
            if(dp[i-1]==0)
                return 0;//前面状态是0，不用在找了
            if(s[i-1]=='0')//前面是0，0跟i-2组成数字
            {
                if(s[i] != '0')
                    dp[i] = dp[i-1];//只能自己组成一个数
            }
            else if(s[i-1]=='1')
            {
                if(s[i]=='0') dp[i]=dp[i-2];//当前是0，0跟i-1组成数字，取dp[i-2]
                else dp[i]= dp[i-1]+dp[i-2];//当前不是0，两种选择
            }
            else if(s[i-1]=='2')
            {
                if(s[i]>'0' && s[i]<='6') dp[i]= dp[i-1]+dp[i-2];
                else if(s[i]=='0') dp[i]=dp[i-2];
                else dp[i] = dp[i-1];
            }
            else//3-9
            {
                if(s[i]=='0') return 0;
                else dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
    }
};