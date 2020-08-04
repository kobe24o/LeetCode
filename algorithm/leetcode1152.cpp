class Solution {
	map<vector<string>,unordered_set<int>> count;
	unordered_map<string, vector<pair<int,string>>> m;
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    	int i, n = username.size();
    	for(i = 0; i < n; i++) 
    	{
    		m[username[i]].push_back({timestamp[i],website[i]});
    	}
    	for(auto it = m.begin(); it != m.end(); ++it)
    	{
    		sort(it->second.begin(), it->second.end(),[&](auto a, auto b){
    			return a.first < b.first;
    		});
    	}
    	vector<string> path;
    	for(auto it = m.begin(); it != m.end(); ++it)
    	{
    		dfs(it->second, path, 0);
    	}
    	int maxcount = 0;
    	vector<vector<string>> result;
    	for(auto it = count.begin(); it != count.end(); ++it)
    	{
    		if(it->second.size() > maxcount)
    		{
    			result.clear();
    			result.push_back(it->first);
    			maxcount = it->second.size();
    		}
    		else if(it->second.size() == maxcount)
    			result.push_back(it->first);
    	}
    	sort(result.begin(), result.end());
    	return result[0];
    }

    void dfs(vector<pair<int,string>>& web, vector<string>& path, int idx)
    {
    	if(path.size()==3)
    	{
    		count[path].insert(web[0].first);
    		return;
    	}
    	for(int i = idx; i < web.size(); ++i)
    	{
    		path.push_back(web[i].second);
    		dfs(web, path, i+1);
    		path.pop_back();
    	}
    }
};