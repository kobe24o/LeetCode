class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> stk1, stk2;
        TreeNode *tp1, *tp2;
        while(original || !stk1.empty())
        {
        	while(original)
        	{
        		stk1.push(original);
        		original = original->left;
        	}
        	while(cloned)
        	{
        		stk2.push(cloned);
        		cloned = cloned->left;
        	}
        	tp1 = stk1.top();
        	tp2 = stk2.top();
        	stk1.pop();
        	stk2.pop();
        	if(tp1 == target)
        		return tp2;
        	original = tp1->right;
        	cloned = tp2->right;
        }
        return NULL;
    }
};