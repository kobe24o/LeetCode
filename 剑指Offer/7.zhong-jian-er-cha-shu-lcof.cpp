class Solution {
	unordered_map<int,int> pre, in;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
        	return NULL;
        int i, n = preorder.size();
        for(i = 0; i < n; ++i)
        {
        	pre[preorder[i]] = i;
        	in[inorder[i]] = i;
        }

        return build(preorder,0,n-1,inorder,0,n-1);
    }

    TreeNode* build(vector<int>& preorder, int sp, int ep, vector<int>& inorder, int si, int ei)
    {
    	if(ep-sp<0)
    		return NULL;
    	TreeNode* root = new TreeNode(preorder[sp]);
    	int Proot = in[preorder[sp]];
    	int leftlen = Proot-si;
    	int rightLen = ei-Proot;
    	root->left = build(preorder,sp+1,sp+leftlen,inorder,si,Proot-1);
    	root->right = build(preorder,sp+leftlen+1,sp+leftlen+rightLen,inorder,Proot+1,ei);
    	return root;
    }
};