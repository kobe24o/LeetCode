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
    unordered_set<char> h[9];
    unordered_set<char> v[9];
    unordered_set<char> box[9];

    bool found = false;
public:
    /**
     * @param board: the sudoku puzzle
     * @return: nothing
     * box_index = (row / 3) * 3 + columns / 3
     */
    void solveSudoku(vector<vector<char>> &board) {
        int i, j, k, count = 0, b_idx;
        vector<vector<bool>> visited (9, vector<bool>(9,false));
        vector<vector<bool>> filled(9, vector<bool>(9,false));
        for(i = 0; i < 9; ++i)
        {
            for(j = 0; j < 9; ++j)
            {
                if(board[i][j]!='.')
                {
                    b_idx = (i/3)*3+j/3;
                    h[i].insert(board[i][j]);
                    v[j].insert(board[i][j]);
                    box[b_idx].insert(board[i][j]);
                    visited[i][j] = true;
                    count++;
                }
            }
        }
        count = 81-count;
        dfs(board,0,0,visited,filled,count);
    }
    void dfs(vector<vector<char>> &board, int x, int y,vector<vector<bool>> &visited,vector<vector<bool>> &filled, int count)
    {
        if(y==9)
        {
            x++;
            y=0;
        }
        if(count==0 || found)
        {
            found = true;
            return;
        }
        int j, k, b_idx;
        for(j = y; j < 9; ++j)
        {
            if(visited[x][j])
                continue;
            b_idx = (x/3)*3+j/3;
            for(k = 1; k <= 9; ++k)
            {
                if(!h[x].count(k+'0') && !v[j].count(k+'0') && !box[b_idx].count(k+'0') && !filled[x][j])
                {
                    filled[x][j] = true;
                    h[x].insert(k+'0');
                    v[j].insert(k+'0');
                    box[b_idx].insert(k+'0');
                    board[x][j] = k+'0';
                    dfs(board, x, j+1,visited,filled,count-1);
                    filled[x][j] = false;
                    h[x].erase(k+'0');
                    v[j].erase(k+'0');
                    box[b_idx].erase(k+'0');
                    board[x][j] = '0';
                }
            }
        }
        if(x==8 && j==9)
        {
            found = true;
        }
    }
};

int main() {
    vector<vector<char>> v4 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {7,5,6,4};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};
    vector<string> st  = {"011000","0111010","01101010"};
    Solution s;
    s.solveSudoku(v4);


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
    return 0;
}