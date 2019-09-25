class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        bt(0,0,target,subset,ans,candidates);
        return ans;
    }
    void bt(int i, int sum, int &target, vector<int> subset, vector<vector<int>> &ans, vector<int> &candidates) 
    {
    	if(i > candidates.size() || sum > target)
    		return;
    	if(i <= candidates.size() && sum == target)
    	{
    		ans.push_back(subset);
    		return;
    	}
    	for(int j = i; j < candidates.size(); j++)
    	{
    		if(j > i && candidates[j-1] == candidates[j])
    			continue;
    		subset.push_back(candidates[j]);
    		bt(j+1, sum+candidates[j], target, subset, ans, candidates);
    		subset.pop_back();
    	}
    }
};