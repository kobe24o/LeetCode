class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        multimap<int,vector<int>> m;
        int i, j, k = 0;
        for(i = 0; i < R; ++i)
        {
        	for(j = 0; j < C; ++j)
        		m.emplace(pair<int,vector<int>> (abs(i-r0)+abs(j-c0),vector<int> ({i,j})));
        }
        for(auto& kv : m)
        	for(auto& vec : kv.second)
        		ans.push_back(vec);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R*C);
        int i, j, k = 0;
        for(i = 0; i < R; ++i)
        	for(j = 0; j < C; ++j)
        		ans[k++] = {i,j};
        sort(ans.begin(), ans.end(), [&](auto& a, auto& b)
        		{return abs(a[0]-r0)+abs(a[1]-c0) < abs(b[0]-r0)+abs(b[1]-c0);});
        return ans;
    }
};

class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R*C);
        bool visited[R][C];
        memset(visited, 0, sizeof visited);
        queue<pair<int,int>> q;
        pair<int,int> tp;
        q.push({r0,c0});
        visited[r0][c0] = true;
        int x, y, k, i = 0;
        while(!q.empty())
        {
        	tp = q.front();
        	q.pop();
        	ans[i++] = {tp.first, tp.second};
        	for(k = 0; k < 4; ++k)
        	{
        		x = tp.first + dir[k][0];
        		y = tp.second + dir[k][1];
        		if(x>=0 && x<R && y>=0 && y<C && !visited[x][y])
        		{
        			q.push({x,y});
        			visited[x][y] = true;
        		}
        	}
        }
        return ans;
    }
};