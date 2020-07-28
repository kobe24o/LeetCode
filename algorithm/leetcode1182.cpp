class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
    	unordered_map<int,set<int>> m;
    	for(int i = 0; i < colors.size(); ++i)
    	{
    		m[colors[i]].insert(i);
    	}
    	vector<int> ans(queries.size(), -1);
    	int l, r, dis, i = 0;
    	for(auto& q : queries)
    	{
    		if(colors[q[0]] == q[1])
    		{
    			ans[i++] = 0;
    			continue;
    		}
    		auto next = m[q[1]].lower_bound(q[0]);
    		r = next==m[q[1]].end() ? INT_MAX : *next-q[0];
    		l = INT_MAX;
    		if(next != m[q[1]].begin())
    		{
    			l = q[0] - *(--next);
    		}
    		dis = min(l, r);
    		ans[i++] = dis==INT_MAX ? -1 : dis;
    	}
    	return ans;
    }
};

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
    	int i, j, n = colors.size(), dis, idx, c;
    	vector<int> pos(4,-1);
    	vector<vector<int>> left(n, vector<int>(4, INT_MAX));
    	vector<vector<int>> right(n, vector<int>(4, INT_MAX));
    	for(i = 0; i < n; ++i)
    	{
    		pos[colors[i]] = i;
    		left[i][1] = pos[1]==-1 ? INT_MAX : i-pos[1];
    		left[i][2] = pos[2]==-1 ? INT_MAX : i-pos[2];
    		left[i][3] = pos[3]==-1 ? INT_MAX : i-pos[3];
    	}
    	pos[1] = pos[2] = pos[3] = -1;
    	for(i = n-1; i >= 0; --i)
    	{
    		pos[colors[i]] = i;
    		right[i][1] = pos[1]==-1 ? INT_MAX : pos[1]-i;
    		right[i][2] = pos[2]==-1 ? INT_MAX : pos[2]-i;
    		right[i][3] = pos[3]==-1 ? INT_MAX : pos[3]-i;
    	}
    	vector<int> ans(queries.size(), -1);
    	for(i = 0; i < queries.size(); ++i)
    	{
    		idx = queries[i][0];
    		c = queries[i][1];
    		dis = min(left[idx][c], right[idx][c]);
    		ans[i] = dis==INT_MAX ? -1 : dis;
    	}
    	return ans;
    }
};