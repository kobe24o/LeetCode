class Solution {
	TreeNode *r1, *r2;
	stack<TreeNode*> s1, s2;
	TreeNode *n1, *n2;
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        r1 = root1;
        r2 = root2;
        vector<int> ans;
        TreeNode *cur1 = iterator1(), *cur2 = iterator2();
        while(cur1 || cur2)
        {
        	if(cur1 && !cur2)
        	{
        		ans.push_back(cur1->val);
        		cur1 = iterator1();
        	}
        	else if(!cur1 && cur2)
        	{
        		ans.push_back(cur2->val);
        		cur2 = iterator2();
        	}
        	else
        	{
        		if(cur1->val <= cur2->val)
        		{
        			ans.push_back(cur1->val);
        			cur1 = iterator1();
        		}
        		else
        		{
        			ans.push_back(cur2->val);
        			cur2 = iterator2();
        		}
        	}
        }
        return ans;
    }

    TreeNode* iterator1()
    {
    	while(r1 || !s1.empty())
    	{
    		while(r1)
    		{
    			s1.push(r1);
    			r1 = r1->left;
    		}
    		n1 = s1.top();
    		s1.pop();
    		r1 = n1->right;
    		return n1;
    	}
    	return NULL;
    }

    TreeNode* iterator2()
    {
    	while(r2 || !s2.empty())
    	{
    		while(r2)
    		{
    			s2.push(r2);
    			r2 = r2->left;
    		}
    		n2 = s2.top();
    		s2.pop();
    		r2 = n2->right;
    		return n2;
    	}
    	return NULL;
    }
};