/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//class Solution {  //DFS
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        if(root)
//        {
//            swap(root->left,root->right);
//            invertTree(root->left);
//            invertTree(root->right);
//        }
//        return root;
//    }
//};
class Solution {//BFS
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            if(temp)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
            swap(temp->left, temp->right);
            q.pop();
        }
        return root;
    }
};