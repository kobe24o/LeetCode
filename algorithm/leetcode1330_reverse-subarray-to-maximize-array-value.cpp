class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int i, j, n=nums.size(), val=0, maxval=INT_MIN, len;
        for(i = 0; i < n-1; i++)
            val += abs(nums[i]-nums[i+1]);
        for(len =2; len < n; ++len)
        {
            for(i = 0; i+len < n; ++i)
            {
                if(i == 0)
                    maxval = max(maxval,val-abs(nums[i+len]-nums[i+len-1])+abs(nums[i+len]-nums[i]));
                else if(i+len == n)
                    maxval = max(maxval,val-abs(nums[i]-nums[i-1])+abs(nums[i+len]-nums[i]));
                else
                    maxval = max(maxval,val-abs(nums[i]-nums[i-1])-abs(nums[i+len]-nums[i+len-1])+abs(nums[i+len]-nums[i])+abs(nums[i+len-1]-nums[i-1]));
            }
        }
        return maxval;
    }
};
