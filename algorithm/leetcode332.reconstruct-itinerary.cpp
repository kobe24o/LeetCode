class Solution {
	unordered_map<string, multiset<string>> m;
	vector<string> ans;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    	for(auto& t : tickets)
    		m[t[0]].insert(t[1]);
    	dfs("JFK");
    	reverse(ans.begin(),ans.end());
    	return ans;
    }
    void dfs(string s)
    {
    	while(m[s].size() != 0)
    	{
    		string to = *m[s].begin();
    		m[s].erase(m[s].begin());
    		dfs(to);
    	}
        ans.push_back(s);
    }
};