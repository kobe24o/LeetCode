class Solution {
	vector<vector<int>> ans;
public:
    vector<vector<int>> getFactors(int n) {	
    	return dfs(n, 2);
    }
    vector<vector<int>> dfs(int n, int div)
    {
    	vector<vector<int>> factor, temp;
    	for(int i = div; i*i <= n; ++i)
    	{
    		if(n%i == 0)
    		{
    			factor.push_back({n/i,i});
    			temp = dfs(n/i, i);
    			for(auto f : temp)
	    		{
	    			f.push_back(i);
	    			factor.push_back(f);
	    		}	
            }  		
    	}
    	return factor;
    }
};