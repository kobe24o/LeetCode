class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // sort(nums.begin(),nums.end()); 错误一发，在这里。。。
        multiset<int> s;
        int presum;
        for(int i = 0, j; i < nums.size(); ++i)
        {
            presum = 0;
            for(j = i; j < nums.size(); ++j)
            {
                presum += nums[j];
                s.insert(presum);
            }
        }
        auto it = s.begin();
        int k = left-1;
        while(k--)
            it++;
        k = right-left+1;
        int sum = 0;
        while(k--)
        {
            sum += *it;
            it++;
        }
        return sum;
    }
};
