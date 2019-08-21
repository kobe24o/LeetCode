class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp_max[nums.size()], dp_min[nums.size()];
        int maxProduct;
        maxProduct = dp_max[0] = dp_min[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] >= 0)
            {
                dp_max[i] = max(nums[i]*dp_max[i-1], nums[i]);
                dp_min[i] = min(nums[i]*dp_min[i-1], nums[i]);
            }
            else//nums[i] < 0
            {     
                dp_max[i] = max(nums[i]*dp_min[i-1], nums[i]);
                dp_min[i] = min(nums[i]*dp_max[i-1], nums[i]);
            }
            if(dp_max[i] > maxProduct)
                maxProduct = dp_max[i];
        }
        return maxProduct;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp_max, dp_min, maxProduct, pre_dp_max;
        maxProduct = dp_max = dp_min = pre_dp_max = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            pre_dp_max = dp_max;
            dp_max = max(max(nums[i]*dp_max,nums[i]*dp_min),nums[i]);
            dp_min = min(min(nums[i]*dp_min,nums[i]*pre_dp_max),nums[i]);
            if(dp_max > maxProduct)
                maxProduct = dp_max;
        }
        return maxProduct;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp_max, dp_min, maxProduct, pre_dp_max;
        maxProduct = dp_max = dp_min = pre_dp_max = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            pre_dp_max = dp_max;
            if(nums[i] >= 0)
            {
                dp_max = max(nums[i]*dp_max, nums[i]);
                dp_min = min(nums[i]*dp_min, nums[i]);
            }
            else//nums[i] < 0
            {     
                dp_max = max(nums[i]*dp_min, nums[i]);
                dp_min = min(nums[i]*pre_dp_max, nums[i]);
            }
            if(dp_max > maxProduct)
                maxProduct = dp_max;
        }
        return maxProduct;
    }
};