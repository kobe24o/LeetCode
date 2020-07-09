struct cmp
{
	bool operator()(vector<double>& a, vector<double>& b)
	{
		return a[0] < b[0];//差值大的在上
	}
};
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> s;
        priority_queue<vector<double>, vector<vector<double>>, cmp> q;
        TreeNode* cur;
        while(root || !s.empty())
        {
        	while(root)
        	{
        		s.push(root);
        		root = root->left;
        	}
        	cur = s.top();
        	s.pop();
        	root = cur->right;
        	if(q.size() < k)
        		q.push({fabs(cur->val-target), double(cur->val)});
        	else if(q.size()==k && q.top()[0] > fabs(cur->val-target))
        	{	//有更小的差值
        		q.pop();
        		q.push({fabs(cur->val-target), double(cur->val)});
        	}
        	if(q.size()==k && cur->val-target >= q.top()[0])
        		break;
        }
        vector<int> ans(k);
        int i = 0;
        while(!q.empty())
        {
        	ans[i++] = q.top()[1];
        	q.pop();
        }
        return ans;
    }
};