class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = binarysearchFirstTarget(nums,target);
        if(i == -1)
        	return 0;
        int count = 0, k;
        for(k = i; k < nums.size(); ++k)
        	if(nums[k] == target)
        		count++;
    	return count;
    }

    int binarysearchFirstTarget(vector<int>& nums, int& target)
    {
    	int l = 0, r = nums.size()-1, mid;
    	while(l <= r)
    	{
    		mid = l +((r-l)>>1);
    		if(nums[mid] < target)
    			l = mid+1;
    		else if(nums[mid] > target)
    			r = mid-1;
    		else
    		{
    			if(mid == 0 || nums[mid-1] != nums[mid])
    				return mid;
    			else
    				r = mid-1;
    		}
    	}
    	return -1;
    }
};