class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        vector<int> flip(n+1, 0);
        int presum = 0;//每个位置的翻转次数
        int ans = 0;
        for(int i = 0; i <= n-K; ++i)
        {   //前面可以翻的位置
            presum += flip[i];
            if((A[i]+presum)%2 == 1)//不用再翻了
                continue;
            else
            {
                flip[i]++;//左端点+1
                ans++;
                flip[i+K]--;//差分，右端点+1的位置 -1
                presum++;//前缀和更新
            }
        }
        for(int i = n-K+1; i < n; i++)
        {   //剩余的不能再翻了，不足K个
            presum += flip[i];
            if((A[i]+presum)%2 == 0)
                return -1;//有不为1的，不能满足全部翻成1
        }
        return ans;
    }
};