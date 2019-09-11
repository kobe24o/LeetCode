class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;//哈希表
        for(int i = 0; i < inorder.size(); ++i) 
        {
            m[inorder[i]] = i;//方便后面查找位置
        }
        return build(postorder, inorder,0,postorder.size()-1,0,inorder.size()-1,m);
    }
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int pS, int pE, int iS, int iE, unordered_map<int,int> &m)
    {
        if(pS > pE)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pE]);
        int leftlen = m[postorder[pE]]-iS;
        root->left = build(postorder,inorder,pS,pS+leftlen-1,iS,m[postorder[pE]]-1,m);
        root->right = build(postorder,inorder,pS+leftlen,pE-1,m[postorder[pE]]+1,iE,m);
        return root;
    }
};

class Solution {    //别人写的 循环
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) 
    {
        if (in.empty()) 
            return NULL;
        stack<TreeNode*> S;
        TreeNode *root = new TreeNode(post.back()), *cur = root;
        S.push(root);
        for (int i = post.size() - 2, j = in.size() - 1; i >= 0; i--) 
        {
            TreeNode *back = NULL, *cur = new TreeNode(post[i]);
            while (!S.empty() && S.top()->val == in[j]) 
            {
                back = S.top(), 
                S.pop(), 
                j--;
            }
            if (back)
                back->left = cur;
            else
                S.top()->right = cur;
            S.push(cur);
        }
        return root;
    }
};