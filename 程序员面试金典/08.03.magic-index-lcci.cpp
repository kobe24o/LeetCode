class Solution {
	bool foundOne = false;
	int idx = INT_MAX;
public:
    int findMagicIndex(vector<int>& nums) {
    	findidx(nums,0,nums.size()-1);
        if(idx == INT_MAX)
            return -1;
    	return idx;
    }

    void findidx(vector<int>& nums,int l, int r)
    {
    	if(l > r)
    		return;
    	int mid = l+((r-l)>>1);
    	if(nums[mid] == mid)
    	{
    		idx = min(idx, mid);
    		foundOne = true;
    	}
    	if(foundOne)
        {   
            if(idx > l)
    		    findidx(nums,l,mid-1);
        }
    	else
    	{
    		findidx(nums,l,mid-1);
    		findidx(nums,mid+1,r);
    	}
    }
};