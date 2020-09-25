class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> one(n);
        for(int i = 0; i < n; ++i)
            one[i] = (i > 0 ? one[i-1] : 0) + (S[i]=='1');
            // 前缀 1 的个数
        vector<int> dp0(n+1, n), dp1(n+1, n);
        // dp0[i] 表示 以 0 结束递增的最小翻转次数
        // dp1[i] 表示 以 1 结束递增的最小翻转次数
        dp0[0] = dp1[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            if(S[i] == '0')//当前是0
            {
                dp0[i+1] = min((i > 0 ? one[i-1] : 0), dp0[i]);
                //以0结束 ，    把前面的 1 都翻过来  or   前面以0结束
                dp1[i+1] = min(dp0[i], dp1[i])+1;
                //以1结束，    前面以0或1结束都可以，再把当前0翻转为1，+1
            }
            else//当前是 1
            {
                dp0[i+1] = min((i > 0 ? one[i-1] : 0), dp0[i])+1;
                //以0结束 ，    把前面的 1 都翻过来  or   前面以0结束， 再把当前1翻转为0，+1
                dp1[i+1] = min(dp0[i], dp1[i]);
                //以1结束，    前面以0或1结束都可以，
            }
        }
        return min(dp0[n], dp1[n]);
    }
};