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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return form(preorder,0,preorder.size()-1);
    }
    TreeNode* form(vector<int>& preorder, int start, int end)
    {
    	if(start > end)
    		return NULL;
    	TreeNode* newroot = new TreeNode(preorder[start]);
        int i;
    	for(i = start+1; i <= end; ++i)
    	{
    		if(preorder[i] > preorder[start])
    			break;
    	}
    	newroot->left = form(preorder,start+1,i-1);
    	newroot->right = form(preorder,i,end);
 		return newroot;
    }
};