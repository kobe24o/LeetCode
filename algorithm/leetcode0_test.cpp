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
    int m, n, i, j, k, step = 0, size, x, y;
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        string ans = "123450", state;
        int x0, y0, xi, yi;
        pair<int,int> xy0;
        queue<string> q;
        unordered_set<string> visited;
        state = boardToString(board);
        if(state == ans)
            return step;
        q.push(state);
        visited.insert(state);
        while(!q.empty())
        {
            step++;
            size = q.size();
            while(size--)
            {
                xy0 = stringToBoard(q.front(), board);
                q.pop();
                x0 = xy0.first;
                y0 = xy0.second;
                for(k = 0; k < 4; ++k)
                {
                    xi = x0+dir[k][0];
                    yi = y0+dir[k][1];
                    if(xi>=0 && xi<m && yi>=0 && yi<n)
                    {
                        swap(board[xi][yi], board[x0][y0]);
                        state = boardToString(board);
                        if(state == ans)
                            return step;
                        if(!visited.count(state))
                        {
                            visited.insert(state);
                            q.push(state);
                        }
                        swap(board[xi][yi], board[x0][y0]);
                    }

                }
            }
        }
        return -1;
    }

    string boardToString(vector<vector<int>>& board)
    {
        string s;
        for (i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                s.push_back(board[i][j]+'0');
        return s;
    }

    pair<int,int> stringToBoard(string &s, vector<vector<int>>& board)
    {
        for (i = m-1; i >= 0; i--)
            for(j = n-1; j >= 0; j--)
            {
                board[i][j] = s.back()-'0';
                s.pop_back();
                if(board[i][j] == 0)
                    x = i, y = j;
            }
        return make_pair(x, y);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> m =
            {{1,2,3},{4,0,5}};
    s.slidingPuzzle(m);
}