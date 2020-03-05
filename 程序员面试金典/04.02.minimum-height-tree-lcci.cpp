class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	return build(nums,0,nums.size()-1);
    }

    TreeNode* build(vector<int>& nums, int l, int r)
    {
    	if(l > r)
    		return NULL;
    	int mid = l+((r-l)>>1);
    	TreeNode* root = new TreeNode(nums[mid]);
    	root->left = build(nums,l,mid-1);
    	root->right = build(nums,mid+1,r);
    	return root;
    }
};