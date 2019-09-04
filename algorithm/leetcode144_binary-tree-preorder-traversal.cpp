class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void preorder(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		ans.push_back(root->val);
        		root = root->left;
        	}
        	root = stk.top()->right;
        	stk.pop();
        }
        return ans;
    }
};