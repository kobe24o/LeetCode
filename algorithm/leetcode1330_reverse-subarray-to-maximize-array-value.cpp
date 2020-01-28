class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int i, j, n = nums.size(), val = 0, maxval = 0;
        for(i = 0; i < n-1; i++)
            val += abs(nums[i]-nums[i+1]);
        if(n <= 2)
            return val;
        maxval = val;
        for(i = 0; i < n; ++i)
        {
            if(i != n-1)
                maxval = max(maxval, val+abs(nums[0]-nums[i+1])-abs(nums[i]-nums[i+1]));//左边界0
            if(i != 0)
                maxval = max(maxval, val+abs(nums[i-1]-nums[n-1])-abs(nums[i]-nums[i-1]));//右边界n-1
        }
        int max1 = INT_MIN, min1 = INT_MAX;
        int max2 = INT_MIN, min2 = INT_MAX;
        int max3 = INT_MIN, min3 = INT_MAX;
        int max4 = INT_MIN, min4 = INT_MAX;
        for(i = 1; i < n-1; ++i)
        {
            max1 = max(max1, nums[i-1]+nums[i]-abs(nums[i]-nums[i-1]));
            max2 = max(max2, nums[i-1]-nums[i]-abs(nums[i]-nums[i-1]));
            max3 = max(max3, -nums[i-1]+nums[i]-abs(nums[i]-nums[i-1]));
            max4 = max(max4, -nums[i-1]-nums[i]-abs(nums[i]-nums[i-1]));
            min1 = min(min1, nums[i-1]+nums[i]+abs(nums[i]-nums[i-1]));
            min2 = min(min2, nums[i-1]-nums[i]+abs(nums[i]-nums[i-1]));
            min3 = min(min3, -nums[i-1]+nums[i]+abs(nums[i]-nums[i-1]));
            min4 = min(min4, -nums[i-1]-nums[i]+abs(nums[i]-nums[i-1]));
        }
        int maxdiff = max(INT_MIN, max(max1-min1, max(max2-min2, max(max3-min3, max4-min4))));
        maxval = max(maxval, val+maxdiff);
        return maxval;
    }
};