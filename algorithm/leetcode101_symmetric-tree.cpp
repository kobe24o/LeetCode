class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return sym(root,root);
    }
    bool sym(TreeNode *t1, TreeNode *t2)
    {
    	if((!t1&&t2)||(t1&&!t2))
    		return false;
    	else if(!t1&&!t2)
    		return true;
    	else
    		return(t1->val==t2->val && sym(t1->left,t2->right)
    				&& sym(t1->right,t2->left));
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *t1, *t2;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty())
        {
        	t1 = q.front();
        	q.pop();
        	t2 = q.front();
        	q.pop();
        	if((!t1&&t2)||(t1&&!t2))
    			return false;
    		else if(!t1&&!t2)
    			continue;
    		else//t1,t2都存在
    		{
    			if(t1->val != t2->val)
    				return false;
    			q.push(t1->left);
    			q.push(t2->right);
    			q.push(t1->right);
    			q.push(t2->left);
    		}
        }
        return true;
    }
};