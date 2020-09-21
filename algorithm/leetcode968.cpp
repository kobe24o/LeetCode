/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	unordered_map<TreeNode*, int> camera0, camera1;
	int mins = 1;
public:
    int minCameraCover(TreeNode* root) {
    	int s = 0;
    	dfs(root, s, 1);
    	dfs(root, s, 0);
    	return mins;
    }
    int dfs(TreeNode* root, int s, bool watch)
    {
    	
    }
};