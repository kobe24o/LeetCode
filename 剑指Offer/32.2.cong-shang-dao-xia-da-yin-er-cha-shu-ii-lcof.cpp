class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        	return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        vector<int> lv;
        TreeNode* tp;
        int size;
        while(!q.empty())
        {
        	size = q.size();
        	while(size--)
        	{
	        	tp = q.front();
	        	q.pop();
	        	lv.push_back(tp->val);
	        	if(tp->left) q.push(tp->left);
	        	if(tp->right) q.push(tp->right);
	        }
	        ans.push_back(lv);
	        lv.clear();
        }
        return ans;
    }
};