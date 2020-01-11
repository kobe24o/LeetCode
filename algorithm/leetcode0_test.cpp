/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    int shortestBridge(vector<vector<int>>& A) {
        queue<pair<int,int>> q;
        queue<pair<int,int>> firstLand;
        int i, j, n = A.size(), k, x, y, step=0, size;
        vector<vector<bool>> visited(n,vector<bool> (n, false));
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
                if(A[i][j])
                {
                    q.push(make_pair(i,j));
                    firstLand.push(make_pair(i,j));
                    visited[i][j] = true;
                    break;
                }
        }
        pair<int,int> tp;
        while(!firstLand.empty())
        {
            tp = firstLand.front();
            firstLand.pop();
            for(k = 0; k < 4; ++k)
            {
                x = tp.first + dir[k][0];
                y = tp.second + dir[k][1];
                if(x>=0 && x<n && y>=0 && y<n && A[x][y] && !visited[x][y])
                {
                    firstLand.push(make_pair(x,y));
                    q.push(make_pair(x,y));
                    visited[x][y] = true;
                }
            }
        }
        bool found = false;
        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                tp = q.front();
                q.pop();
                for(k = 0; k < 4; ++k)
                {
                    x = tp.first + dir[k][0];
                    y = tp.second + dir[k][1];
                    if(x>=0 && x<n && y>=0 && y<n && !visited[x][y])
                    {
                        if(A[x][y] == 0)
                        {
                            q.push(make_pair(x,y));
                            visited[x][y] = true;
                        }
                        else
                        {
                            found = true;
                            break;
                        }
                    }
                }
                if(found)
                    break;
            }
            step++;
            if(found)
                break;

        }
        return step-1;
    }
};
int main()
{
    vector<vector<int>> m = {{0,1,0,0,0},{0,1,0,1,1},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};
    Solution s;
    s.shortestBridge(m);
}