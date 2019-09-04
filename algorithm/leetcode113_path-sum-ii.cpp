class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
         if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> way;
        path(root, 0, sum, way, ans);
        return ans;
    }
    void path(TreeNode *root, int cursum, int &sum, vector<int> way, vector<vector<int>> &ans)
    {
        if(!root)
            return;
        way.push_back(root->val);
        path(root->left, cursum+root->val, sum, way, ans);
        way.pop_back();
        way.push_back(root->val);
        path(root->right, cursum+root->val, sum, way, ans);
        if(!root->left && !root->right && cursum+root->val == sum)
        {
            ans.push_back(way);
        }
    }
};