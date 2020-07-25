class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
    	unordered_map<int,int> count;
    	int i, maxcount = 0, n = nums.size();
    	for(i = 0; i < n; ++i)
    	{
    		count[nums[i]]++;
    		maxcount = max(maxcount, count[nums[i]]);
    	}
    	return maxcount*K <= n;
    }
};