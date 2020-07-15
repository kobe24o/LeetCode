class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
    	unordered_map<int,int> m;
    	m[0] = -1;
    	int i, sum = 0, maxlen = 0;
    	for(i = 0; i < nums.size(); ++i)
    	{
    		sum += nums[i];
    		if(m.count(sum-k))
    			maxlen = max(maxlen, i-m[sum-k]);
    		if(!m.count(sum))
    			m[sum] = i;
    	}
    	return maxlen;
    }
};