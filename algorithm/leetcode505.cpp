class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size(), i, j, k, x, y, delta;
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        queue<vector<int>> q;
        vector<vector<int>> dis(m, vector<int>(n,INT_MAX));
        dis[start[0]][start[1]] = 0;
        q.push(start);
        while(!q.empty())
        {
            i = q.front()[0];
            j = q.front()[1];
            q.pop();
            for(k = 0; k < 4; ++k)
            {
                x = i;
                y = j;
                delta = 0;
                while(x+dir[k][0]>=0 && x+dir[k][0]<m && y+dir[k][1]>=0 && y+dir[k][1]<n
                        && maze[x+dir[k][0]][y+dir[k][1]]==0)
                {
                    x += dir[k][0];
                    y += dir[k][1];
                    delta++;//走的步数增量
                }
                if(dis[i][j]+delta < dis[x][y])//该方向下一个位置为墙壁，停在这
                {
                    dis[x][y] = dis[i][j]+delta;
                    q.push({x,y});
                }
            }
        }
        return dis[destination[0]][destination[1]]==INT_MAX ? -1 : dis[destination[0]][destination[1]];
    }
};

struct cmp
{
    bool operator()(const vector<int>& a, const vector<int>& b) const
    {
        return a[2] > b[2];//距离小的在顶
    }
};
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size(), i, j, k, x, y, curstep, delta;
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        priority_queue<vector<int>,vector<vector<int>>, cmp> q;
        vector<vector<int>> dis(m, vector<int>(n,INT_MAX));
        dis[start[0]][start[1]] = 0;
        start.push_back(0);//第三个参数是距离
        q.push(start);
        while(!q.empty())
        {
            i = q.top()[0];
            j = q.top()[1];
            curstep = q.top()[2];
            q.pop();
            if(dis[i][j] < curstep)//距离不是最短的
                continue;
            for(k = 0; k < 4; ++k)
            {
                x = i;
                y = j;
                delta = 0;
                while(x+dir[k][0]>=0 && x+dir[k][0]<m && y+dir[k][1]>=0 && y+dir[k][1]<n
                        && maze[x+dir[k][0]][y+dir[k][1]]==0)
                {
                    x += dir[k][0];
                    y += dir[k][1];
                    delta++;//走的步数增量
                }
                if(dis[i][j]+delta < dis[x][y])//该方向下一个位置为墙壁，停在这
                {
                    dis[x][y] = dis[i][j]+delta;
                    q.push({x,y,dis[x][y]});
                }
            }
        }
        return dis[destination[0]][destination[1]]==INT_MAX ? -1 : dis[destination[0]][destination[1]];
    }
};
