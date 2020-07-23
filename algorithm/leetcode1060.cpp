class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
    	int i = 0, n = nums.size(), ans;
    	for(i = 0; i < n-1; ++i)
    	{
    		if(nums[i+1]-nums[i]-1 < k)
    			k -= nums[i+1]-nums[i]-1;
    		else
    		{
    			ans = nums[i]+k;
    			return ans;
    		}
    	}
    	return nums[n-1]+k;
    }
};

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1, mid, miss;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            miss = countmissing(nums, mid);
            if(miss < k)
                l = mid+1;
            else if(miss > k)
                r = mid-1;
            else
                return nums[mid]-1;

        }
        return nums[r]+k-countmissing(nums,r);
    }
    int countmissing(vector<int>& nums, int i)
    {
        return nums[i]-nums[0]-i;
    }
};