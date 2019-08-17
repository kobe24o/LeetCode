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
            	calcTreeDepth(root->left, height, mincount);
           	if(root->right)
               	calcTreeDepth(root->right, height, mincount);
    	}
    	else
    	{
    		if(height < mincount)
    			mincount = height;
    	}
    }
};