class Solution {
	int count = 0;
public:
    int countNodes(TreeNode* root) {
    	if(root == NULL)
    		return 0;
    	count++;
    	countNodes(root->left);
    	countNodes(root->right);
    	return count;
    }
};

class Solution {
	int h;
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
        	return 0;
        int hL = leftHeight(root);
        int hR = rightHeight(root);
        if(hL == hR)
        	return pow(2,hL)-1;
        else//hL > hR
        {
        	return 1+countNodes(root->left)+countNodes(root->right);
        }
    }

    int leftHeight(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
    	for(h = 0 ; root; root = root->left;)
    		++h;
    	return h;
    }

    int rightHeight(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
    	for(h = 0 ; root; root = root->right;)
    		++h;
    	return h;
    }
};