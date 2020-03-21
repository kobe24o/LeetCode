class Solution {
	bool found = false;
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
    	if(!t2)
    		return true;
    	else if(!t1)
    		return false;
    	if(t1->val == t2->val)
    	{
    		found = check(t1, t2);
    	}
    	checkSubTree(t1->left, t2);
    	checkSubTree(t1->right, t2);
    	return found;
    }

    bool check(TreeNode* t1, TreeNode* t2) 
    {
    	if(found)
    		return true;
    	if(!t1 && t2)
    		return false;
    	else if(!t2)
    		return true;
    	else
    	{
    		if(t1->val != t2->val)
    			return false;
    		return check(t1->left, t2->left) && check(t1->right, t2->right);
    	}
    }
};