class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int cursum, maxsum = INT_MIN, n, i = 0, id;
        queue<TreeNode*> q;
        TreeNode* tp;
        q.push(root);
        while (!q.empty()) 
        {
        	n = q.size();
        	cursum = 0;
        	while(n--)
        	{
        		tp = q.front();
        		q.pop();
        		cursum += tp->val;
        		if(tp->left)
        			q.push(tp->left);
        		if(tp->right)
        			q.push(tp->right);
        	}
        	i++;
        	if(cursum > maxsum)
        	{
        		maxsum = cursum;
        		id = i;
        	}
        }
        return id;
    }
};