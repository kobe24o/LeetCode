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
    vector<vector<string>> ans;
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<string> map(n,string(n,'.'));
        for(int i = 0; i < n; ++i)
        {

            map[0][i]='Q';
            dfs(map,0,i,n);
            map[0][i]='.';

        }
        return ans;
    }

    bool isok(vector<string>& map, int x, int y, int &n)
    {
        int i = 1, j = y;
        while(j >= 1)
        {
            if(map[x][j-1]=='Q')
                return false;
            if(x-i>=0 && map[x-i][j-1]=='Q')
                return false;
            if(x+i<n && map[x+i][j-1]=='Q')
                return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(vector<string>& map, int x, int y, int& n)
    {
        if(x==n-1)
        {
            ans.push_back(map);
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            if(x+1 < n && isok(map,x+1,i,n))
            {
                map[x+1][i] = 'Q';
                dfs(map, x+1, i, n);
                map[x+1][i] = '.';
            }
        }
    }
};

int main() {
    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {7,5,6,4};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};

    Solution s;
    s.solveNQueens(2);


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