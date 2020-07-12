class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), i, j, sum = 0;
        for(int i = 0; i < n; ++i)
        {
            for(j = i+1; j < n; ++j)
                if(nums[i] == nums[j])
                    sum++;
        }
        return sum;
    }
};
