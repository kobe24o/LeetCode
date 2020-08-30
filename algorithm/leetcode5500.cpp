class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxlen = 0, i, pos = 0, neg = -1, n = nums.size(), p = 1;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] < 0)
            {
                p *= -1;//乘积变号
                if(neg == -1)//第一次负数
                    neg = i;
            }
            else if(nums[i] == 0)//乘积为0
            {
                p = 1;
                pos = i+1;
                neg = -1;
            }
            if(p > 0)
                maxlen = max(maxlen, i-pos+1);
            else if(p < 0)
                maxlen = max(maxlen, i-neg);
        }
        return maxlen;
    }
};