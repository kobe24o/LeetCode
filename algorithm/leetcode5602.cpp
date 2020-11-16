class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0;
        unordered_map<int,int> presum;
        presum[0] = 0;//前缀和为0时，长度为0
        for(int i = 0; i < n; i++) 
        {
            sum += nums[i];
            presum[sum] = i+1;//前缀和对应的长度
        }
        int tailsum = 0, minlen = INT_MAX;
        if(presum.find(x) != presum.end())
            minlen = presum[x];
        for(int i = n-1; i >= 0; i--)
        {
            tailsum += nums[i];
            int target = x - tailsum;
            if(presum.find(target) != presum.end() && presum[target] < i)
            {
                minlen = min(minlen, presum[target]+n-i);
            }
        }
        return minlen==INT_MAX ? -1 : minlen;
    }
};