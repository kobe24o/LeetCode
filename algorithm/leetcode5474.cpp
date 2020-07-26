
class Solution {
    int ans = 0;
public:
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int distance)
    {
        if(!root) return {};
        auto l = dfs(root->left,distance);
        auto r = dfs(root->right,distance);
        if(!root->left && !root->right)
        {
            vector<int> dis(distance+1,0);
            dis[1] = 1;
            return dis;
        }
        for(int i = 1; i < min(int(l.size()),distance+1); ++i)
            for(int j = 1; j < min(int(r.size()),distance+1); ++j)
                if(i+j <= distance)
                    ans += l[i]*r[j];
        vector<int> dis(distance+1, 0);
        for(int i = 1; i+1 <= distance; ++i)
            dis[i+1] += (i < l.size() ? l[i] : 0) + (i < r.size() ? r[i] : 0);
        return dis;
    }
};