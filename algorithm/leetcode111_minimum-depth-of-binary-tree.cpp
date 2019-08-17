#include <iostream>
#include <climits>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//class Solution {//DFS
////public:
////    int minDepth(TreeNode* root) {
////        if(root == NULL)
////            return 0;
////        int leftHeight, rightHeight;
////        if(root->left && root->right)
////        {
////            leftHeight = minDepth(root->left);
////            rightHeight = minDepth(root->right);
////        }
////        else if(root->left && !root->right)
////        {
////            leftHeight = minDepth(root->left);
////            rightHeight = INT_MAX;
////        }
////        else if(!root->left && root->right)
////        {
////            leftHeight = INT_MAX;
////            rightHeight = minDepth(root->right);
////        }
////        else
////        {
////            leftHeight = rightHeight = 0;
////        }
////        return min(leftHeight, rightHeight)+1;
////    }
////};

class Solution {//BFS
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int height = 0, n;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            height++;
            n = q.size();
            while(n--)
            {
                if(!q.front()->left && !q.front()->right)//第一个叶子节点退出
                    return height;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return height;
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
//    root->right = new TreeNode(20);
//    root->right->left = new TreeNode(15);
//    root->right->right = new TreeNode(7);
    Solution s;
    cout << s.minDepth(root);
}