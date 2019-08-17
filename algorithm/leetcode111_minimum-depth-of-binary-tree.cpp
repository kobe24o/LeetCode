class Solution {
public:
    int minDepth(TreeNode* root) {
        int mincount = INT_MAX;
        if(root)
        	calMinDepth(root,0,mincount);
        return mincount;
    }
    void calMinDepth(TreeNode* root, int height, int &mincount)
    {
    	if(root)
    	{
    		height++;
    		if(root->left)
            	calMinDepth(root->left, height, mincount);
           	if(root->right)
               	calMinDepth(root->right, height, mincount);
    	}
    	else
    	{
    		if(height < mincount)
    			mincount = height;
    	}
    }
};