class Solution {
    static bool cmp(const pair<string,int> &a,const pair<string,int> &b) 
	{
		if(a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    	queue<int> q;
    	int n = watchedVideos.size(), i, j, tp, size, lv = 0;
    	vector<bool> visited(n,false);
    	q.push(id);
    	visited[id] = true;
    	vector<int> lvfriend;
    	while(!q.empty())
    	{
    		size = q.size();
    		while(size--)
    		{
    			tp = q.front();
    			q.pop();
    			if(lv == level)
    				lvfriend.push_back(tp);
    			for(i = 0; i < friends[tp].size(); ++i)
    			{
    				if(!visited[friends[tp][i]])
    				{
    					q.push(friends[tp][i]);
    					visited[friends[tp][i]] = true;
    				}
    			}
    		}
    		lv++;
    		if(lv > level)
    			break;
    	}
    	unordered_map<string,int> m;
    	for(i = 0; i < lvfriend.size(); ++i)
    	{
    		for(j = 0; j < watchedVideos[lvfriend[i]].size(); ++j)
                m[watchedVideos[lvfriend[i]][j]]++;
    	}
        vector<pair<string,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
    	vector<string> ans(v.size());
    	for(i = 0; i < v.size(); ++i)
    		ans[i] = v[i].first;
    	return ans;
    }
};