class bst_iter
{
	stack<TreeNode*> s;
	TreeNode* cur;
	int v;
	bool postorder;
public:
	bst_iter(TreeNode* root, bool postorder = false)
	{
		cur = root;
		this->postorder = postorder;
	}
	int next()
	{
		if(!postorder && (cur || !s.empty()))
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			v = s.top()->val;
			cur = s.top()->right;
			s.pop();
			return v;
		}
		else if(postorder && (cur || !s.empty()))
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->right;
			}
			v = s.top()->val;
			cur = s.top()->left;
			s.pop();
			return v;
		}
		return INT_MAX;
	}
};
class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    	bst_iter bstit1(root1);//ascending
    	bst_iter bstit2(root2,true);//descending
    	int v1 = bstit1.next(), v2 = bstit2.next();
    	while(v1 != INT_MAX && v2 != INT_MAX)
    	{
    		if(v1+v2 < target)
    			v1 = bstit1.next();
    		else if(v1+v2 > target)
    			v2 = bstit2.next();
    		else
    			return true;
    	}
    	return false;
    }
};