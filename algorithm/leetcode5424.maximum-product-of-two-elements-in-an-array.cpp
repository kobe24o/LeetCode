class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), i, m1 = 0, m2 = 0;
        for(i = 0; i < n; ++i)
        {
            if(nums[i] >= m1)
            {
                m2 = m1;
                m1 = nums[i];
            }
            else if(nums[i] > m2)
                m2 = nums[i];
        }
        return (m1-1)*(m2-1);
    }
};