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
    vector<vector<int>> d = {{0,1},{1,0},{-1,0},{0,-1}};//右0，下1，上2，左3
    vector<vector<vector<int>>> dir = {{},{d[0],d[3]},{d[1],d[2]},{d[1],d[3]},{d[0],d[1]},{d[2],d[3]},{d[0],d[2]}};
    bool found = false;
    int m,n;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dfs(grid,0,0);
        return found;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(found)
            return;
        if(i==m-1 && j==n-1)
        {
            found = true;
            return;
        }
        int x, y, k, dx, dy;
        for(k = 0; k < dir[grid[i][j]].size(); ++k)
        {
            dx = dir[grid[i][j]][k][0];
            dy = dir[grid[i][j]][k][1];
            x = i+dx;
            y = j+dy;
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y] != -1 && isok(grid,dx,dy,x,y))
            {
                grid[x][y] = -1;//标记走过
                return dfs(grid,x,y);
            }
        }
    }

    bool isok(vector<vector<int>>& grid, int &dx, int &dy, int &x, int &y)
    {
        if(dx == 1 && dy ==0)//往下走，对应x,y处 '上' 要开着
        {
            if(grid[x][y]==2 || grid[x][y]==5 || grid[x][y]==6)
                return true;
        }
        else if(dx == 0 && dy == 1)//右   --左
        {
            if(grid[x][y]==1 || grid[x][y]==3 || grid[x][y]==5)
                return true;
        }
        else if(dx == -1 && dy == 0)//上 ---下
        {
            if(grid[x][y]==2 || grid[x][y]==3 || grid[x][y]==4)
                return true;
        }
        else if(dx == 0 && dy == -1)//左--- 右
        {
            if(grid[x][y]==1 || grid[x][y]==4 || grid[x][y]==6)
                return true;
        }
        return false;
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
    vector<int> v1 = {0,0,1,0};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{2,4,3},{6,5,2}};
    vector<string> st  = {"T1S.",".*0*","....","..*."};
    Solution s;
    cout << s.hasValidPath(v2) << endl;

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