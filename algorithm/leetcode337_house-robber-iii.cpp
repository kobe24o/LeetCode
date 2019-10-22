class Solution {
	map<pair<TreeNode*,bool>,int> m;
public:
    int rob(TreeNode* root) {
        return max(rob(root,0),rob(root,1));
    }
    int rob(TreeNode* root, bool steal)
    {
    	if(root == NULL)
    		return 0;
    	if(m.find(make_pair(root,steal)) != m.end())
    		return m[make_pair(root,steal)];
    	int noStealLeft = rob(root->left,0);
    	int noStealRight = rob(root->right,0);
    	m[make_pair(root->left,0)] = noStealLeft;
    	m[make_pair(root->right,0)] = noStealRight;
    	if(steal)
    		return root->val + noStealLeft + noStealLeft;
    	else//没有偷root
    	{
    		int stealLeft = rob(root->left,1);
    		int stealRight = rob(root->right,1);
    		m[make_pair(root->left,1)] = stealLeft;
    		m[make_pair(root->right,1)] = stealRight;
    		return max(noStealLeft,stealLeft)+max(noStealLeft,stealRight);
    	}
    }
};