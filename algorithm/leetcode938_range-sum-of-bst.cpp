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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        sumLR(root,L,R,sum);
        return sum;
    }
    void sumLR(TreeNode* root,int &L,int &R,int &sum)
    {
    	if(root == NULL)
    		return;
    	if(root->val >= L && root->val <= R)
		{
			sum += root->val;
			sumLR(root->left,L,R,sum);
    		sumLR(root->right,L,R,sum);
		}
    	else if(root->val < L)
    	{//左子树都小于L，砍了
    		sumLR(root->right,L,R,sum);
    	}
    	else if(root->val > R)
    	{//右子树都大于R，砍了
    		sumLR(root->left,L,R,sum);
    	}
    }
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root->left;
        	}
        	root = stk.top();
        	stk.pop();
        	if(root->val >= L && root->val <= R)
        		sum += root->val;
        	else if(root->val > R)//中序非降，后面都大于R
        		break;
        	root = root->right;
        }
        return sum;
    }
};