#include <iostream>
#include <climits>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        if(!root)
//            return true;
//        long prev = INT64_MIN;
//        bool valid = true;
//        isValid(root, prev, valid);
//        return valid;
//    }
//    void isValid(TreeNode* root, long &prev, bool &valid)
//    {
//        if(!valid || !root)
//            return;
//        isValid(root->left, prev, valid);
//        if(valid)
//            valid = (root->val > prev);
//        prev = root->val;
//        isValid(root->right, prev, valid);
//    }
//};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        long prev = INT64_MIN;
        bool valid = true;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while(cur != NULL || !stk.empty())
        {
            while(cur != NULL)
            {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if(cur->val <= prev)
                return false;
            prev = cur->val;
            cur = cur->right;
        }
        return valid;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    Solution s;
    cout << s.isValidBST(root);
}