class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int i, j, cnt, ans = 0;
    	for(i = 0; i < 32; ++i)
    	{
    		cnt = 0;
    		for(j = 0; j < nums.size(); ++j)
    		{
    			if(nums[j]&(1<<i))
    				cnt++;
    		}
    		if(cnt%3)
    			ans |= (1<<i);
    	}
    	return ans;
    }
};