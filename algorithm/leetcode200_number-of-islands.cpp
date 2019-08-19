#include <vector>
#include <iostream>
#include <queue>

using namespace std;
//class Solution//DFS
//{
//public:
//    int numIslands(vector<vector<char>>& grid)
//    {
//        int i, j, numofislands = 0;
//        for(i = 0; i < grid.size(); ++i)
//        {
//            for(j = 0; j < grid[i].size(); ++j)
//            {
//                if(grid[i][j] == '1')
//                {
//                    numofislands++;
//                    dfs(grid,i,j);
//                }
//            }
//        }
//        return numofislands;
//    }
//    void dfs(vector<vector<char>>& grid, int i, int j)
//    {
//        grid[i][j] = '0';//标记走过了，修改了地图（不影响解题）
//        if(i-1 >= 0 && grid[i-1][j] == '1')
//            dfs(grid,i-1,j);
//        if(j-1 >= 0 && grid[i][j-1] == '1')
//            dfs(grid,i,j-1);
//        if(i+1 < grid.size() && grid[i+1][j] == '1')
//            dfs(grid,i+1,j);
//        if(j+1 < grid[i].size() && grid[i][j+1] == '1')
//            dfs(grid,i,j+1);
//    }
//};

class Solution//BFS
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int i, j, numofislands = 0;
        for(i = 0; i < grid.size(); ++i)
        {
            for(j = 0; j < grid[i].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    numofislands++;
                    bfs(grid,i,j);
                }
            }
        }
        return numofislands;
    }
    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        queue<pair<int,int> > q;
        q.push(make_pair(i,j));
        int r, c;
        while(!q.empty())
        {
            r = q.front().first;
            c = q.front().second;
            grid[r][c] = '0';//标记走过了，修改了地图（不影响解题）
            q.pop();
            if(inrange(grid,r-1,c) && grid[r-1][c] == '1')
                q.push(make_pair(r-1,c));
            if(inrange(grid,r,c-1) && grid[r][c-1] == '1')
                q.push(make_pair(r,c-1));
            if(inrange(grid,r+1,c) && grid[r+1][c] == '1')
                q.push(make_pair(r+1,c));
            if(inrange(grid,r,c+1) && grid[r][c+1] == '1')
                q.push(make_pair(r,c+1));
        }
    }
    bool inrange(vector<vector<char>>& grid, int i, int j)
    {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
    }
};

int main(int argc, char** argv)
{
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution s;
    std::cout << s.numIslands(grid);
    return 0;
}