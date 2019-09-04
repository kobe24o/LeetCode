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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
        	return -1;
        int minNum = root->val;
        long secMinNum = LONG_MAX;
        findSec(root,minNum,secMinNum);
        if(secMinNum != LONG_MAX)
        	return secMinNum;
        return -1;
    }

    void findSec(TreeNode* root, int &minNum, long &secMinNum)
    {
    	if(!root)
    		return;
    	if(root->val > minNum && root->val < secMinNum)
    	{
    		secMinNum = root->val;
    	}
    	findSec(root->left,minNum,secMinNum);
        findSec(root->right,minNum,secMinNum);
    }
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
        	return -1;
        int minNum = root->val;
        long secMinNum = LONG_MAX;
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		if(root->val > minNum && root->val < secMinNum)
        			secMinNum = root->val;
        		root = root->left;
        	}
        	root = stk.top()->right;
        	stk.pop();
        }
        if(secMinNum != LONG_MAX)
        	return secMinNum;
        return -1;
    }
};