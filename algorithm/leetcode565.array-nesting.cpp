class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    	int maxlen = 0, len = 0, idx = 0, prev;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		if(nums[i] == -1)
    			continue;
    		idx = i;
    		len = 0;
    		while(idx != -1 && nums[idx] != -1)
    		{
    			len++;
    			prev = idx;
                idx = nums[idx];
    			nums[prev] = -1;
    		}
    		maxlen = max(maxlen, len);
    	}
    	return maxlen;
    }
};