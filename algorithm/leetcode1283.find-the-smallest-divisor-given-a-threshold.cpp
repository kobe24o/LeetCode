class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    	int i, l = 1, r = 1000000, mid, sum;
    	while(l < r)
    	{
    		mid = l+((r-l)>>1);
    		sum = 0;
    		for(i = 0; i < nums.size(); ++i)
	    		sum += ceil(nums[i]/double(mid));
    		if(sum > threshold)
    			l = mid+1;
    		else
    			r = mid;
    	}
    	return l;
    }
};