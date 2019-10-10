class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid, s = -1, e = -1;
        s = finds(0,r,nums,target);
        if(s == -1)
        	return {-1,-1};
        e = finde(s,r,nums,target);
        return {s,e};
    }
    int finds(int l, int r, vector<int>& nums,int &target)
    {//找第一个等于target的数
    	int mid;
    	while(l <= r)
        {
        	mid = l+((r-l)>>1);
        	if(nums[mid] == target)
        	{
        		if(mid == 0 || nums[mid-1] != target)
        			return mid;
        		else
        			r = mid-1;
        	}
        	else if(nums[mid] < target)
        		l = mid+1;
        	else
        		r = mid-1;
        }
        return -1;
    }
    int finde(int l, int r, vector<int>& nums, int &target)
    {//找最后一个等于target的数
    	int mid;
    	while(l <= r)
        {
        	mid = l+((r-l)>>1);
        	if(nums[mid] == target)
        	{
        		if(mid == nums.size()-1 || nums[mid+1] != target)
        			return mid;
        		else
        			l = mid+1;
        	}
        	else if(nums[mid] < target)
        		l = mid+1;
        	else
        		r = mid-1;
        }
        return -1;
    }
};