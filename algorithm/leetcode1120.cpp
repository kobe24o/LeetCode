class Solution {
	double maxAVG = 0.0;
public:
    double maximumAverageSubtree(TreeNode* root) {
    	dfs(root);
        return maxAVG;
    }
    vector<int> dfs(TreeNode* root)
    {
    	if(!root) return {0, 0};//空节点的和 0，节点个数0
    	auto l = dfs(root->left);
    	auto r = dfs(root->right);
    	int n = 1+l[1]+r[1];//总节点个数
    	int sum = root->val+l[0]+r[0];
    	double avg = sum/double(n);
    	if(avg > maxAVG)
    		maxAVG = avg;
    	return {sum, n};
    }
};