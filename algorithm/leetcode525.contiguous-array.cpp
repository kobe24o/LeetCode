class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    	int i, n = nums.size(), sum = 0, maxlen = 0;
    	unordered_map<int,int> m;//sum, 第一次出现sum时的idx
        m[0] = -1;
    	for(i = 0; i < n; ++i)
    	{
    		if(nums[i])
    			sum += 1;
    		else
    			sum -= 1;
    		if(!m.count(sum))
    			m[sum] = i;
    		else
    			maxlen = max(maxlen, i-m[sum]);
    	}
    	return maxlen;
    }
};