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
public:
    /**
     * @param s: the list of binary string
     * @return: the max distance
     */
    int getAns(vector<string> &s) {
        trieTree t;
        for(string& si : s)
            t.insert(si);

        dfs(t.root);
        return sum;
    }

    int dfs(trie* root)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        else if(root->left && !root->right)
            return dfs(root->left);
        else if(!root->left && root->right)
            return dfs(root->right);
        else if(root->left && root->right)
        {
            int l = dfs(root->left)+1;
            int r = dfs(root->right)+1;
            sum = max(sum, l+r);
            return max(l,r);
        }

    }
};

int main() {
    vector<vector<int>> v = {{1,3,2},{4,6,5},{7,9,8},{13,15,14},{10,12,11}};
    vector<int> v1 = {7,5,6,4};
    vector<int> v3 = {21,44,5,21,33,38,23,5,25,43};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<int>> v2 = {{3,7,8},{9,11,13},{15,16,17}};
    vector<string> st  = {"011000","0111010","01101010"};
    Solution s;
    s.getAns(st);


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