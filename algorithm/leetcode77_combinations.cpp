class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> subset;
        bt(1, n, 0, k, subset, ans);
        return ans;
    }
    void bt(int i, int &n, int time, int &k, vector<int> subset, vector<vector<int>>& ans)
    {
    	if(time == k)
    	{
    		ans.push_back(subset);
    		return;
    	}
    	for(int j = i; j <= n; ++j)
    	{
    		subset.push_back(j);
    		bt(j+1,n,time+1,k,subset, ans);
    		subset.pop_back();
    	}
    }
};