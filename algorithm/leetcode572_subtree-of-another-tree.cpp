class Solution {
	TreeNode *cur, *temp;
	stack<TreeNode*> stk;
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
		cur = s;
		bool ans = false;
		TreeNode *Si = next();
		while(!ans && Si != NULL)
		{
			ans = isSub(Si,t);
			Si = next();
		}
    	return ans;
    }

    bool isSub(TreeNode *s, TreeNode *t)
    {
    	if(!s && !t)
    		return true;
    	else if((!s && t) || (s && !t))
    		return false;
        if(s->val == t->val)
        	return isSub(s->left,t->left)&&isSub(s->right,t->right);
        return false;
    }

    TreeNode* next()
    {
    	while(cur || !stk.empty())
    	{
    		while(cur)
    		{
    			stk.push(cur);
    			cur = cur->left;
    		}
    		temp = stk.top();
    		cur = stk.top()->right;
    		stk.pop();
    		return temp;
    	}
    	return NULL;
    }
};