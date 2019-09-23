class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0, n, minlen = INT_MAX;
        unordered_map<int, int> m, start, end;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if(m.find(nums[i]) == m.end())
        	{
        		m[nums[i]] = 1;
        		start[nums[i]] = i;
        		end[nums[i]] = i;
        	}
        	else
        	{
        		m[nums[i]]++;
        		end[nums[i]] = i;
        	}
        }
        for(auto it = m.begin(); it != m.end();++it)
        {
        	if(it->second > degree)
        	{
        		degree = it->second;
        	}
        }
        for(auto it = m.begin(); it != m.end(); ++it)
        {
        	if(it->second == degree)
        	{
        		if(end[it->first]-start[it->first]+1 < minlen)
        			minlen = end[it->first]-start[it->first]+1;
        	}
        }
        return minlen;
    }
};