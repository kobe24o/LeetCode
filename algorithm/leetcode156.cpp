class Solution {//C++
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
    	if(!root || !root->left) return root;
    	TreeNode* l = root->left;//左右子节点存取来
    	TreeNode* r = root->right;
        root->left = NULL;//上下断开
        root->right = NULL;
    	TreeNode* p = upsideDownBinaryTree(l);//根节点
        l->left = r;//跟上面连接起来
        l->right = root;
        return p;
    }
};