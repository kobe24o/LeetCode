class Solution {
	vector<vector<int>> C;
	int mod = 1e9+7;
public:
    int numOfWays(vector<int>& nums) {
    	int n = nums.size();
    	C = vector<vector<int>> (n+1, vector<int>(n+1, 0));
    	C[1][0] = 1, C[1][1] = 1;
    	for(int i = 2, j; i <= n; ++i)
    	{
    		for(j = 0; j <= i; ++j)
    		{
    			if(j==0 || j==i)
    				C[i][j] = 1;
    			else
    			{
    				C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
    			}
    		}
    	}
    	return (dfs(nums)-1)%mod;
    }
    long long dfs(vector<int> &nums)
    {
    	if(nums.size() <= 1)
    		return 1;
    	int root = nums[0], n = nums.size();
    	vector<int> l, r;
    	for(int num : nums)
    	{
    		if(num < root)
    			l.push_back(num);
    		else if(num > root)
    			r.push_back(num);
    	}
    	long long nL = dfs(l), nR = dfs(r);
    	return (((C[n-1][l.size()]*nL)%mod)*nR)%mod;
    }
};