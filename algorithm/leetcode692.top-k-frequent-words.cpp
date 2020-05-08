struct cmp
{
	bool operator()(const pair<string,int>& a, const pair<string,int>& b)
	{
		if(a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
	}
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    	unordered_map<string,int> m;
    	for(string& s : words)
    		m[s]++;
    	priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> q;
    	for(auto& mi : m)
    	{
    		if(q.size() < k)
    			q.push(mi);
    		else
    		{
    			if(mi.second > q.top().second)
    			{
    				q.pop();
    				q.push(mi);
    			}
    			else if(mi.second == q.top().second && mi.first < q.top().first)
    			{
    				q.pop();
    				q.push(mi);
    			}
    		}
    	}
    	vector<string> ans;
    	while(!q.empty())
    	{
    		ans.push_back(q.top().first);
    		q.pop();
    	}
    	reverse(ans.begin(), ans.end());
    	return ans;
    }
};