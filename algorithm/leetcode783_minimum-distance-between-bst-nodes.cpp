class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int dis = INT_MAX, val, preval, i = 0;
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->left;
        	}
        	++i;
        	val = stk.top()->val;
        	if(i != 1 && val-preval < dis)
        		dis = val-preval;
        	preval = val;
        	root = stk.top()->right;
        	stk.pop();
        }
        return dis;
    }
};