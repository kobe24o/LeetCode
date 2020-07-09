class dsu
{
public:
    unordered_map<int,int> f;

    dsu(int n, vector<vector<int>>& positions, int cols)
    {
        f.resize(n);
        int pos;
        for(int i = 0; i < n; ++i)
        {
        	pos = positions[i][0]*cols+positions[i][1];
        	f[pos] = pos;
        }
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
            a = f[a];
        return f[origin] = a;
    }
    int countUni(vector<vector<int>> &grid)
    {
        int count = 0, x, y, n = grid[0].size();
        for(int i = 0; i < f.size(); ++i)
        {	
            x = i/n, y = i-x*n;
            if(i == find(i) && grid[x][y]==1)
                count++;
        }
        return count;
    }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    	int N = m*n, pos, x, y;
    	vector<vector<int>> grid(m,vector<int>(n,0));
    	dsu u(positions.size(),vector<vector<int>>& positions, n);
    	vector<int> ans(positions.size());
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	for(int i = 0, k; i < positions.size(); ++i)
    	{
            grid[positions[i][0]][positions[i][1]] = 1;
            pos = positions[i][0]*n+positions[i][1];
    		for(k = 0; k < 4; ++k)
    		{
    			x = positions[i][0] + dir[k][0];
                y = positions[i][1] + dir[k][1];
    			if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1)
    				u.merge(pos, x*n+y);
    		}
    		ans[i] = u.countUni(grid);
    	}
    	return ans;
    }
};

class dsu
{
public:
    vector<int> f;
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
    }
    bool merge(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        if(fa != fb)
        {
            f[fa] = fb;
            return true;
        }
        return false;//返回是否被合并了
    }
    int find(int a)
    {
        int origin = a;
        while(a != f[a])
            a = f[a];
        return f[origin] = a;
    }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    	int N = m*n, pos, x, y;
    	vector<vector<int>> grid(m,vector<int>(n,0));
    	dsu u(N);
    	vector<int> ans(positions.size());
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        unordered_set<int> s;//有重复的岛屿！！！
    	for(int i = 0, k; i < positions.size(); ++i)
    	{
            ans[i] = (i>0 ? ans[i-1] : 0 )+1;//先把这个岛屿算作孤立+1
            grid[positions[i][0]][positions[i][1]] = 1;//标记为岛屿
            pos = positions[i][0]*n+positions[i][1];//对应并查集中的位置
            if(s.count(pos))//有该岛屿了，重复添加
            {
                ans[i]--;
                continue;
            }
            s.insert(pos);
    		for(k = 0; k < 4; ++k)
    		{
    			x = positions[i][0] + dir[k][0];
                y = positions[i][1] + dir[k][1];//周围坐标x,y
    			if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1)
                {
                    if(u.merge(pos, x*n+y))//合并了
                        ans[i]--;//减1
                }
    		}
    	}
    	return ans;
    }
};