class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
        	return {};
        vector<vector<int> > ans;
        vector<int> temp;
        cs(candidates, 0, target, target, ans, temp);
        return ans;
    }
    void cs(vector<int>& candidates, int idx, int &target, int cursum, vector<vector<int>>& ans, vector<int> temp)
    {
    	if(cursum == 0)
    	{
    		ans.push_back(temp);
    		return;
    	}
    	if(cursum < 0)
    		return;
    	for(int i = idx; i < candidates.size(); ++i)
    	{
    		temp.push_back(candidates[i]);
    		cs(candidates, i, target, cursum-candidates[i], ans, temp);
    		temp.pop_back();
    	}
    }
};