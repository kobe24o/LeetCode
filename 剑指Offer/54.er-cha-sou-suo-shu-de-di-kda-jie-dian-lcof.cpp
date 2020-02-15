class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        //右根左降序遍历
        stack<TreeNode*> s;
        while(root || !s.empty())
        {
        	while(root)
        	{
        		s.push(root);
        		root = root->right;
        	}
        	root = s.top();
        	s.pop();
        	k--;
        	if(k==0)
        		return root->val;
        	root = root->left;
        }
        return -1;
    }
};

class Solution {
	bool found = false;
	int ans;
public:
    int kthLargest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }

    void dfs(TreeNode* root, int& k)
    {
    	if(!root || found)
        	return;
        dfs(root->right,k);
        k--;
        if(k == 0)
        {
        	found = true;
        	ans = root->val;
        }
        dfs(root->left,k);
    }
};