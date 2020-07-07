class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	int i, j, k, n = nums.size(), count = 0, sum;
    	for(int i = 0; i < n-2; ++i)
    	{
    		j = i+1, k = n-1;
    		while(j < k)
    		{
    			sum = nums[i]+nums[j]+nums[k];
    			if(sum < target)
    				count += k-j, j++;
    			else if(sum >= target)
    				k--;
    		}
    	}
    	return count;
    }
};