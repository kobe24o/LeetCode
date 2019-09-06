class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> ans;
        walk(root, path, ans);
        return ans;
    }
    void walk(TreeNode* root, string path, vector<string>& ans) 
    {
    	if(root == NULL)
    		return;
    	walk(root->left, path+to_string(root->val)+"->", ans);
    	walk(root->right, path+to_string(root->val)+"->", ans);
    	if(!root->left && !root->right)
        {
            path += to_string(root->val);
            ans.push_back(path);   
        }
    }
};