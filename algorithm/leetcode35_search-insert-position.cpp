class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int i;
        for(i = 0; i < nums.size(); ++i)
        {
        	if(target <= nums[i])
    		{
        		return i;
        	}
        }
        return i;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target <= nums[0])
        	return 0;
        if(target > nums[nums.size()-1])
        	return nums.size();
        int i = 0, j = nums.size()-1, mid;
        while(i <= j)
        {
        	mid = i + (j-i)/2;
        	if(nums[mid] == target)
        		return mid;
        	else if(nums[mid] > target)
        		j = mid-1;
        	else
        		i = mid+1;
        }
        return j+1;
    }
};