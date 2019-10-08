class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while(left <= right) 
        {
        	mid = left+((right-left)>>1);
        	if(nums[mid] == target)
        		return mid;
        	if(nums[left] <= nums[mid])//左边有序 =不能少
        	{
        		if(nums[left] <= target && target < nums[mid])
        			right = mid-1;
        		else
        			left = mid+1;
        	}
	        else	//右边有序
	        {
	        	if(nums[mid] < target && target <= nums[right])
        			left = mid+1;
        		else
        			right = mid-1;
	        }
        }
        return -1;
    }
};