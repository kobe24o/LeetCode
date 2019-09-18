class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
    	if(!root)
    		return true;
        bool flag = true;
        int val = root->val;
        judge(root,flag,val);
        return flag;
    }
    void judge(TreeNode* root, bool &flag, int &val)
    {
    	if(!root || flag == false)
    		return;
    	if(root->val != val)
    	{
    		flag = false;
    		return;
    	}
    	judge(root->left,flag,val);
    	judge(root->right,flag,val);
    }
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
    	if(!root)
    		return true;
    	int rootval = root->val;
    	stack<TreeNode*> stk;
    	TreeNode *cur;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->left;
        	}
        	root = stk.top();
        	if(root->val != rootval)
        		return false;
        	stk.pop();
        	root = root->right;
        }
        return true;
    }
};