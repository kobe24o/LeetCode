class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL)
        	return NULL;
        if(root->val < L)//该节点和其左子树均删除
        {
        	return trimBST(root->right,L,R);
        }
        else if(root->val > R)
        {
        	return trimBST(root->left,L,R);
        }
        else
        {
        	root->left = trimBST(root->left,L,R);
        	root->right = trimBST(root->right,L,R);
        	return root;
        }   
    }
};