class dsu
{
	vector<int> f;
public:
	dsu(int n)
	{
		f.resize(n);
		for(int i = 0; i < n; ++i)
			f[i] = i;
	}
	void merge(int a, int b)
	{
		int fa = find(a);
		int fb = find(b);
		f[fa] = fb;
	}
	int find(int a)
	{
		int origin = a;
		while(a != f[a])
		{
			a = f[a];
		}
		return f[origin] = f[a];
	}
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
    	dsu u(N+1);
    	sort(connections.begin(), connections.end(),[&](auto a, auto b){
    		return a[2] < b[2];//距离短的边优先
    	});
    	int edge = 0, p1, p2, dis, total = 0;
    	for(int i = 0; i < connections.size(); ++i)
    	{
    		p1 = connections[i][0];
    		p2 = connections[i][1];
    		dis = connections[i][2];
    		if(u.find(p1) != u.find(p2))//两个还未链接
    		{
    			u.merge(p1,p2);
    			edge++;
    			total += dis;
    		}
    		if(edge == N-1)
    			break;
    	}
    	return edge==N-1 ? total : -1;
    }
};

//---------------
//
struct cmp
{
	bool operator()(const pair<int,int>& a, const pair<int,int>& b) const
	{
		return a.second > b.second;//小顶堆, 距离小的优先
	}
};
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
		vector<bool> vis(N+1, false);
    	vector<vector<pair<int,int>>> edges(N+1,vector<pair<int,int>>());
    	for(auto& c : connections)
        {
            edges[c[0]].push_back({c[1],c[2]});
            edges[c[1]].push_back({c[0],c[2]});
        }
    	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
    	int to, distance, total = 0, edge = 0;
        vis[1] = true;
        for(auto& e : edges[1])
            q.push(e);           
    	while(!q.empty())
    	{
    		to = q.top().first;
    		distance = q.top().second;
    		q.pop();
    		if(!vis[to])
            {
                vis[to] = true;
                total += distance;
                edge++;
                if(edge == N-1)
                    return total;
                for(auto& e : edges[to])
                    q.push(e);           
            }
    	}
    	return -1;
    }
};