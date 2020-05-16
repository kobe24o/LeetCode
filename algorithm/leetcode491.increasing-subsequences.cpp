class Solution {
	vector<vector<int>> ans;
	vector<int> path;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, nums);
    	return ans;
    }
    void dfs(int i, vector<int> &nums)
    {
        unordered_set<int> s;
    	for( ; i < nums.size(); ++i)
    	{
            if(s.count(nums[i]))
                continue;
    		if(path.empty() || path.back() <= nums[i])
    		{
    			path.push_back(nums[i]);
                s.insert(nums[i]);
    			if(path.size() > 1)
    				ans.push_back(path);
    			dfs(i+1, nums);
    			path.pop_back();
    		}
    	}
    }
};