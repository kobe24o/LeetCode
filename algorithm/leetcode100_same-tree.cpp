class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        	return true;
        bool ans = true;
        same(p,q,ans);
        return ans;
    }
    void same(TreeNode* r1, TreeNode* r2, bool &ans) 
    {
    	if(ans == false)
    		return;
    	if(!r1 && !r2)
		{
			ans = true;
			return;
		}
    	if(r1 && r2 && r1->val == r2->val)
    	{
    		same(r1->left,r2->left,ans);
    		same(r1->right,r2->right,ans);
    	}
    	else
    		ans = false;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        	return true;
        if((p && !q)||(!p && q))
        	return false;
        queue<TreeNode*> q1, q2;
        q1.push(p),q2.push(q);
        while(1)
        {
        	if(q1.front()->val != q2.front()->val)
        	{
        		return false;
        	}
        	if(q1.front()->left && q2.front()->left)
        		q1.push(q1.front()->left),
        		q2.push(q2.front()->left);
    		else if((q1.front()->left && !q2.front()->left)
    				||(!q1.front()->left && q2.front()->left))
    			return false;
    		if(q1.front()->right && q2.front()->right)
        		q1.push(q1.front()->right),
        		q2.push(q2.front()->right);
    		else if((q1.front()->right && !q2.front()->right)
    				||(!q1.front()->right && q2.front()->right))
    			return false;
    		q1.pop(),q2.pop();
    		if((q1.empty()&&!q2.empty())||(!q1.empty()&&q2.empty()))
    			return false;
    		if(q1.empty()&&q2.empty())
    			return true;
        }
        return true;
    }
};