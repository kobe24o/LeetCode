/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> stk;
    TreeNode *cur;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    /** @return the next smallest number */
    int next() {
        if(!hasNext())
            return -1;
        while(cur)
        {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        int v = cur->val;
        stk.pop();
        cur = cur->right;
        return v;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty() || cur;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */