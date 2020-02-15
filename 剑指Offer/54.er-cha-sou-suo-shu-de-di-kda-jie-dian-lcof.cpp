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