class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.push_back(INT_MIN);
        reverse(nums.begin(), nums.end());
        nums.push_back(INT_MIN);
        reverse(nums.begin(), nums.end());
        int i = 1, j = nums.size()-2, mid;
        while(i <= j)
        {
        	mid = i+((j-i)>>1);
        	if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
        		return mid-1;
        	if(nums[mid] > nums[mid+1])
        		j = mid-1;
        	else
        		i = mid+1;
        }
        return mid-1;
    }
};