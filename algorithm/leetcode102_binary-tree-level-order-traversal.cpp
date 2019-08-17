class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        int lvNum;
        vector<vector<int>> ans;
        vector<int> level;
        q.push(root);
        while(!q.empty())
        {
            lvNum = q.size();
            while(lvNum--)
            {
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                level.push_back(q.front()->val);
                q.pop();
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};