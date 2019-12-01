class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
        	return {};
        queue<TreeNode*> q;
        TreeNode *tp;
        q.push(root);
        vector<int> ans;
        int n, MAX;
        while(!q.empty())
        {
        	n = q.size();
        	MAX = INT_MIN;
        	while(n--)
        	{
        		tp = q.front();
        		MAX = max(MAX, tp->val);
        		q.pop();
        		if(tp->left)
        			q.push(tp->left);
        		if(tp->right)
        			q.push(tp->right);
        	}
        	ans.push_back(MAX);
        }
        return ans;
    }
};