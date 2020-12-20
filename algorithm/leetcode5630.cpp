class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, i = 0, j = 0, n = nums.size();
        vector<int> presum(nums);
        for(int i = 1; i < n; i++) 
            presum[i] += presum[i-1];//前缀和
        unordered_set<int> s;
        while(j < n)
        {
            if(s.find(nums[j]) == s.end())
            {
                s.insert(nums[j]);
            }
            else//存在nums[j]
            {
                while(nums[i] != nums[j])
                {
                    s.erase(nums[i++]);
                }
                i++;//左端点和nums[j]一样的数跳过了
            }
            ans = max(ans, i>0 ? presum[j]-presum[i-1] : presum[j]);
            j++;
        }
        return ans;
    }
};