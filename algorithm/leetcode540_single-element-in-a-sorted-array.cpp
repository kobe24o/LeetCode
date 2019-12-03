class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	int ans = 0;
        for(int i = 0; i < nums.size(); ++i)
        	ans ^= nums[i];
        return ans;
    }
};

class Solution {
	bool found = false;
	int ans;
public:
    int singleNonDuplicate(vector<int>& nums) {
    	find(nums,0,nums.size()-1);
    	return ans;
    }

    void find(vector<int>& nums, int l, int r)
    {
    	if(found || l > r)
    		return;
    	int mid = l+((r-l)>>1);
    	if((mid == 0 && nums[mid] != nums[mid+1])
    		|| (mid == nums.size()-1 && nums[mid-1] != nums[mid]))
    	{
    		found = true;
    		ans = nums[mid];
    	}
    	else if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
    	{
    		found = true;
    		ans = nums[mid];
    	}
    	else
    	{
    		find(nums,l,mid-1);
    		find(nums,mid+1,r);
    	}
    }
};