class Solution {
	bool found = false;
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;
        if(A->val == B->val)
        {
        	found = check(A, B);
        	if(found)
        		return found;
        }
        isSubStructure(A->left,B);
        isSubStructure(A->right,B);
        return found;
    }

    bool check(TreeNode* A, TreeNode* B)
    {
    	if(found || !B || !A)
    	{
    		if(found || !B)
    			return true;
    		return false;
    	}
    	if(A->val == B->val)
    	{
    		return (check(A->left,B->left)&&check(A->right,B->right));
    	}
    	return false;
    }
};