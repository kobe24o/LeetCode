class Solution {
	TreeNode *nodeX = NULL;
	int X;
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) { 
        X = x;
        int count = 0, numOfLeft = 0, numOfRight = 0, remaining, maxNodes;
        preOrder(root,count);
        preOrder(nodeX->left,numOfLeft);
        preOrder(nodeX->right,numOfRight);
        remaining = n-1-numOfLeft-numOfRight;
        maxNodes = max(remaining,max(numOfRight,numOfLeft));
        return maxNodes > n-maxNodes;
    }

    void preOrder(TreeNode* root, int &num)
    {
    	if(root == NULL)
    		return;
    	if(root->val == X)
    		nodeX = root;
    	num++;
    	preOrder(root->left,num);
    	preOrder(root->right,num);
    }
};