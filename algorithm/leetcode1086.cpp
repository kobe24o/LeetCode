class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
    	vector<vector<int>> ans;
    	map<int,priority_queue<int,vector<int>,greater<int>>> m;
    	int id, v;
    	for(auto& i : items)
    	{
    		id = i[0];
    		v = i[1];
    		if(m[id].size()<5)
    			m[id].push(v);
    		else if(m[id].size()==5 && m[id].top() < v)
    		{
    			m[id].pop();
    			m[id].push(v);
    		}
    	}
    	for(auto it = m.begin(); it != m.end(); ++it)
    	{
    		id = it->first;
    		v = 0;
    		while(!m[id].empty())
    		{
    			v += m[id].top();
    			m[id].pop();
    		}
    		ans.push_back({id,v/5});
    	}
    	return ans;
    }
};