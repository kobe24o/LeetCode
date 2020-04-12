class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
    	map<int,int> m;
    	int i, j=0, n = queries.size();
    	for(i = 1; i <= m; ++i)
    		m[i] = i-1;
    	vector<int> ans(n);
    	for(i = 0; i < n; ++i)
    	{
    		ans[j++] = m[queries[i]];
    		m[queries[i]] = 0;
    		for(auto mi : m)
    		{
    			if(mi.second < m[queries[i]])
    				mi.second++;
    		}
    	}
    	return ans;
    }
};