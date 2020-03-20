/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;

class Solution {
    int m, n, step = INT_MAX;
    vector<int> start;
    vector<int> end;
    int bao = 0, count = 0;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int minSteps(vector<string> &maze) {
        int i, j, k, x, y, x0, y0;
        m = maze.size(), n = maze[0].size();
        queue<vector<int>> q;
        vector<int> tp;
        bool foundT = false;

        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(maze[i][j] == 'S')
                {
                    start.push_back(i);
                    start.push_back(j);
                }
                else if(maze[i][j] == 'T')
                {
                    end.push_back(i);
                    end.push_back(j);
                }
                else if(isdigit(maze[i][j]))
                {
                    bao++;
                }
            }
        }
        q.push(start);
        vis[start[0]][start[1]] = true;
        while(!q.empty())
        {
            tp = q.front();
            q.pop();
            x0 = tp[0], y0 = tp[1];
            for(k = 0; k < 4; ++k)
            {
                x = x0+dir[k][0];
                y = y0+dir[k][1];
                if(x>=0&&x<m&&y>=0&&y<n&&maze[x][y]!='*'&&!vis[x][y])
                {
                    q.push({x,y});
                    vis[x][y] = true;
                    if(isdigit(maze[x][y]))
                        count++;
                    else if(maze[x][y]=='T')
                        foundT = true;
                }
            }
        }
        if(count!=bao || !foundT)
            return -1;
        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
                vis[i][j] = false;
        }
        vis[start[0]][start[1]] = true;
        dfs(start[0],start[1],0,0,vis,maze);
        return step;
    }

    void dfs(int x, int y, int count,int s, vector<vector<bool>> &vis,vector<string> &maze)
    {
        if(count == bao && x==end[0] && y==end[1])
        {
            step = min(step, s);
            return;
        }
        int xi, yi;
        for(int k = 0; k < 4; ++k)
        {
            xi = x +dir[k][0];
            yi = y + dir[k][1];
            if(xi>=0&&xi<m&&yi>=0&&yi<n&&maze[xi][yi]!='*'&&!vis[xi][yi])
            {
                vis[xi][yi] = true;
                if(isdigit(maze[xi][yi]))
                    count++;
                dfs(xi,yi,count,s+1,vis,maze);
                vis[xi][yi] = false;
                if(isdigit(maze[xi][yi]))
                    count--;
            }
        }
    }
};

//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11
//["01","1000000","11111111"] 13
//则当前节点所构成的最大距离即左深度+右深度-2*当前节点深度。

//["...1","..S.","..*.",".0.T"]   9

int main() {
    vector<vector<char>> v4 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {7,5,6,4};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};
    vector<string> st  = {"T1S.",".*0*","....","..*."};
    Solution s;
    cout << s.minSteps(st) << endl;

    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    t1->left = t2;
    t2->right = t3;
    t3->left = t4;
    t3->right = t5;


    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    vector<int> a = {1,2,3};
    cout << a.size() << endl;
    a.resize(a.size()+5);
    cout << a.size() << endl;
    for(int i = 0; i < 8; ++i)
        cout << a[i] << endl;
    return 0;
}