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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i = 0; i < inorder.size(); ++i) 
        {
        	m[inorder[i]] = i;//方便后面查找位置
        }
        return build(preorder, inorder,0,preorder.size()-1,0,inorder.size()-1,m);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pS, int pE, int iS, int iE, unordered_map<int,int> &m)
    {
    	if(pS > pE)
    		return NULL;
    	TreeNode *root = new TreeNode(preorder[pS]);
    	int leftlen = m[preorder[pS]]-iS;
    	root->left = build(preorder,inorder,pS+1,pS+leftlen,iS,m[preorder[pS]]-1,m);
    	root->right = build(preorder,inorder,pS+1+leftlen,pE,m[preorder[pS]]+1,iE,m);
    	return root;
    }
};

class Solution {//别人写的，循环法
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) 
    {
		if (pre.empty()) 
			return NULL;
		stack<TreeNode*> S;
		TreeNode* root = new TreeNode(pre[0]);
		S.push(root);
		for (int i = 1, j = 0; i < pre.size(); i++) 
		{  // i-前序序号，j-中序序号
			TreeNode *back = NULL, *cur = new TreeNode(pre[i]);
			while (!S.empty() && S.top()->val == in[j]) 
			{
				back = S.top(), 
				S.pop(), 
				j++;
			}	
			if (back)
			  	back->right = cur;
			else
			  	S.top()->left = cur;
			S.push(cur);
		}
		return root;
    }
};