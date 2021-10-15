#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;


// using namespace std;
// class Solution {
//     vector<vector<int>> ans;
//     vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
//     int t;
// public:
//     vector<vector<int>> bicycleYard(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle) {
//         int m = terrain.size(), n = terrain[0].size();
//         // vector<vector<bool>> vis = vector<vector<bool>> (m, vector<bool>(n, false));
//         for(int i = 0; i < m; ++i)
//         {
//             for(int j = 0; j < n; ++j)
//             {
//                 if(i != position[0] && j != position[1])
//                 {
//                     t = terrain[position[0]][position[1]]-terrain[i][j];
//                     if (t < 0)
//                         continue;
//                     vector<vector<bool>> vis = vector<vector<bool>> (m, vector<bool>(n, false));
//                     // vis[position[0]][position[1]]=true;
//                     if(dfs(position[0], position[1], terrain, obstacle, vis, 0, m, n, i, j))
//                         ans.push_back({i, j});
//                     // vis[position[0]][position[1]]=false;
//                 }
//             }
//         }
        
//         // vector<vector<int>> res;
//         // for(auto& x : ans)
//         //     res.push_back(x);
//         // sort(res.begin(), res.end());
//         return ans;    
//     }
//     bool dfs(int x, int y, vector<vector<int>>& h, vector<vector<int>>& o, vector<vector<bool>>& vis, int val, int m, int n, int i, int j)
//     {
//         if(val > t) return false;
//         for(int k = 0;k < 4; ++k)
//         {
//             int nx = x+dir[k][0];
//             int ny = y+dir[k][1];
//             if(nx>=0&&nx<m && ny>=0&&ny<n)
//             {
//                 int o2 = o[nx][ny];
//                 int v = val+o2;
//                 if (v <= t)
//                 {
//                     // vis[nx][ny] = true;
//                     if((v==t && nx==i && ny==j) || dfs(nx, ny, h, o, vis, v, m, n, i,j))
//                         return true;
//                     // 
//                     // vis[nx][ny] = false;
//                 }
//             }
//         }
//         return false;
//     }
// };

int main()
{

    // Solution s;
    // vector<int> position = {0,0};
    // vector<vector<int>>  terrain = {{0,0},{0,0}}, obstacle = {{0,0},{0,0}};
    // s.bicycleYard(position, terrain, obstacle);
    string s = "hello";
    cout << s << endl; 
    system("pause");
    return 0;
}