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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
    TreeNode* build(vector<int>& nums, int start, int end) 
    {
    	if(start > end)
    		return NULL;
    	int maxNum = INT_MIN, midx;
    	TreeNode *node;
    	for(int i = start; i <= end; ++i)
    	{
    		if(nums[i] > maxNum)
    		{
    			maxNum = nums[i];
    			midx = i;
    		}
    	}
		node = new TreeNode(maxNum);
		node->left = build(nums, start, midx-1);
		node->right = build(nums, midx+1, end);
    	return node;
    }
};