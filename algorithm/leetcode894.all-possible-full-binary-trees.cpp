class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if((N&1)==0)//偶数节点不存在满二叉树
            return {};
        if(N==1)
        {
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        vector<TreeNode*> ans;
        for(int n1 = 1; N>0 && n1 < N; n1+=2)
        {
            vector<TreeNode*> l = allPossibleFBT(n1);
            vector<TreeNode*> r = allPossibleFBT(N-1-n1);
            for(auto lnode : l)
                for(auto rnode : r)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = lnode;
                    root->right = rnode;
                    ans.push_back(root);
                }
        }
        return ans;
    }
};