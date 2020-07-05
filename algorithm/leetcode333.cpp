class Solution {
	int maxNode = 1;
public:
    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return maxNode;
    }

    vector<int> dfs(TreeNode* root)//返回子树min,max,node个数,是bst？
    {								//       0   1    2       3
    	if(!root) 
    		return {INT_MAX,INT_MIN,0,1};
    	auto l = dfs(root->left);
    	auto r = dfs(root->right);
    	bool bst = (l[3] && r[3] && l[1] < root->val && root->val < r[0]);
    	int node = l[2]+r[2]+1;
        int MAX = !root->right ? root->val : r[1],
            MIN = !root->left ? root->val : l[0];
    	if(bst)
    		maxNode = max(maxNode, node);
    	return {MIN,MAX,node,bst};
    }
};