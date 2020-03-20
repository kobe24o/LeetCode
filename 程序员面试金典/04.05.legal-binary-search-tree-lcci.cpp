class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	stack<TreeNode*> stk;
    	TreeNode* tp, *prev = NULL;
    	while(root || !stk.empty())
    	{
    		while(root)
    		{
    			stk.push(root);
    			root = root->left;
    		}
    		tp = stk.top();
    		stk.pop();
    		if(prev != NULL && prev->val >= tp->val)
    			return false;
    		prev = tp;
    		root = tp->right;
    	}
    	return true;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        bool ans = true;
        check(root,ans);
        return ans;
    }

    vector<int> check(TreeNode* root, bool& ans)
    {
        if(ans == false)
        	return {-1,-1};
        if(!root)
        	return {};
        vector<int> l, r;
        if(root->left)
        	l = check(root->left, ans);
        if(root->right)
        	r = check(root->right, ans);
        if(l.empty() && r.empty())
        	return {root->val, root->val};
        else if(!l.empty() && r.empty())
        {
        	if(l[1] >= root->val)
        		ans = false;
        	return {min(l[0],root->val), max(l[1],root->val)};
        }
        else if(l.empty() && !r.empty())
        {
        	if(r[0] <= root->val)
        		ans = false;
        	return {min(r[0],root->val), max(r[1],root->val)};
        }
        else
        {
        	if(l[1] >= root->val || r[0] <= root->val)
        		ans = false;
        	return {l[0], r[1]};
        }
        
    }
};

class Solution {
    bool ans = true;
    long prevVal = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if(!root || ans == false)
            return true;
        isValidBST(root->left);
        if(root->val <= prevVal)
            ans = false;
        else
            prevVal = root->val;
        isValidBST(root->right);
        return ans;
    }
};