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

class trie
{
public:
    char ch;
    trie* left;
    trie* right;
    bool isend;
    trie(char c)
    {
        ch = c;
        left = right = NULL;
        isend = false;
    }
};

class trieTree
{
public:
    trie *root;
    trieTree(){
        root = new trie('*');
    }
    void insert(string s)
    {
        trie* cur = root;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '0')
            {
                if(!cur->left)
                    cur->left = new trie('0');
                cur = cur->left;
            }
            else
            {
                if(!cur->right)
                    cur->right = new trie('1');
                cur = cur->right;
            }
        }
        cur->isend = true;
    }

};

class Solution {
    int sum = 0;
    bool found = false;
    trie *node = NULL;
public:
    int getAns(vector<string> &s) {
        trieTree t;
        for(string& si : s)
            t.insert(si);

        dfs(t.root,0);
        int l = findpath(node->left);
        int r = findpath(node->right);
        return l+r;
    }

    void dfs(trie* root, int count)
    {
        if(!root)
            return;
        if((root->left && root->right) || root->isend)
        {
            found = true;
            node = root;
            return;
        }
//        if((root->isend && root->left) || (root->isend && root->right))
//        {
//            node = root;
//        }
        dfs(root->left,count+1);
        dfs(root->right,count+1);
    }

    int findpath(trie* root)
    {
        if(!root)
            return 0;
        int l = findpath(root->left);
        int r = findpath(root->right);
        return max(l,r)+1;
    }
};

//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11

int main() {
    vector<vector<char>> v4 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    vector<int> v1 = {7,5,6,4};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};
    vector<string> st  = {"011000","0111011","01001010"};
    Solution s;
    cout << s.getAns(st) << endl;


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