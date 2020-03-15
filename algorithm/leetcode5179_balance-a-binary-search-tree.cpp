class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)
            return root;
        stack<TreeNode*> s;
        vector<TreeNode*> v;
        TreeNode* tp;
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            tp = s.top();
            s.pop();
            root = tp->right;
            tp->left = NULL;
            tp->right = NULL;
            v.push_back(tp);
        }
        return build(v,0,v.size()-1);
    }

    TreeNode* build(vector<TreeNode*>& v, int l, int r)
    {
        if(l > r)
            return NULL;
        int mid = l+((r-l)>>1);
        TreeNode* root = v[mid];
        root->left = build(v,l,mid-1);
        root->right = build(v,mid+1,r);
        return root;
    }
};