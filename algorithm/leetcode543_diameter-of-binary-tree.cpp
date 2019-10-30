class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        diameter(root,maxDiameter);
        return maxDiameter;
    }

    int diameter(TreeNode* root, int &maxDiameter) 
    {
        if(root == NULL)
        	return 0;
        int left = diameter(root->left,maxDiameter);
        int right = diameter(root->right,maxDiameter);
        int curMax = left+right;//包含当前根节点的直径为L+R
        if(curMax > maxDiameter)
        	maxDiameter = curMax;
        return max(left,right)+1;
        //给别人用的话，只能选取一侧，再加上root
    }
};