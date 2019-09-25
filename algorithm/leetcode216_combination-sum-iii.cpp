class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cb;
        bt(0,0,k,0,n,cb,ans);
        return ans;
    }
    void bt(int num, int i, int &k, int sum, int &n, vector<int> cb, vector<vector<int>> &ans) 
    {
    	if(sum > n || (i == k && sum != n))
    		return;
    	if(i == k && sum == n)
    	{
    		ans.push_back(cb);
    		return;
    	}
    	for(int j = num+1; j <= 9; ++j)
    	{
    		cb.push_back(j);
    		bt(j,i+1,k,sum+j,n,cb,ans);
    		cb.pop_back();
    	}
    }
};