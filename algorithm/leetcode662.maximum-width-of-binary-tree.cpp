class Solution {
	int ans;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        vector<unsigned long> LeftPosOflv;
        ans = 1;
        dfs(root, 0, 0, LeftPosOflv);
        return ans;
    }
    void dfs(TreeNode* root, int depth, unsigned long pos, vector<unsigned long> &LeftPosOflv)
    {
    	if(!root) return;
    	if(LeftPosOflv.size() <= depth)//第一次遇到的是该层最左边的
    		LeftPosOflv.push_back(pos);
    	ans = max(ans, int(pos-LeftPosOflv[depth]+1));
    	dfs(root->left, depth+1, 2*pos+1, LeftPosOflv);
    	dfs(root->right, depth+1, 2*pos+2, LeftPosOflv);
    }
};