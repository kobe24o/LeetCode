class Solution {
	TreeNode *begin, *end, *temp;
	stack<TreeNode*> s1, s2;
public:
    bool findTarget(TreeNode* root, int k) {
        begin = end = root;
        TreeNode *i = next(), *j = prev();
        while(i != j)
        {
        	if(i->val+j->val > k)
        		j = prev();
        	else if(i->val+j->val < k)
        		i = next();
        	else//if(i->val+j->val == k)
        		return true;
        }
        return false;
    }

    TreeNode* next()
    {
    	while(begin)
    	{
    		s1.push(begin);
    		begin = begin->left;
    	}
    	temp = s1.top();
    	s1.pop();
    	begin = temp->right;
    	return temp;
    }

    TreeNode* prev()
    {
    	while(end)
    	{
    		s2.push(end);
    		end = end->right;
    	}
    	temp = s2.top();
    	s2.pop();
    	end = temp->left;
    	return temp;
    }
};