class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	unordered_set<int> s;
    	int maxlen = 0, curlen = 0, n;
        for(int i = 0; i < nums.size(); ++i)
        {
        	s.insert(nums[i]);
        }
        for(int i = 0; i < nums.size(); ++i)
        {
        	if(s.find(nums[i]-1) == s.end())
        	//nums[i]是连续数字的起点
        	{
        		curlen = 1;
        		n = nums[i];
        		while(s.find(n+1) != s.end())
        			++curlen, ++n;
        	}
        	maxlen = max(maxlen,curlen);
        }
        return maxlen;
    }
};