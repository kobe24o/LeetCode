#include <vector>
#include <iostream>
using namespace std;
class Solution
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
                    dfs(grid,i,j);
                }
            }
        }
        return numofislands;
    }
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '0';//标记走过了，修改了地图（不影响解题）
        if(i-1 >= 0 && grid[i-1][j] == '1')
            dfs(grid,i-1,j);
        if(j-1 >= 0 && grid[i][j-1] == '1')
            dfs(grid,i,j-1);
        if(i+1 < grid.size() && grid[i+1][j] == '1')
            dfs(grid,i+1,j);
        if(j+1 < grid[i].size() && grid[i][j+1] == '1')
            dfs(grid,i,j+1);
    }
};

int main(int argc, char** argv)
{
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution s;
    std::cout << s.numIslands(grid);
    return 0;
}