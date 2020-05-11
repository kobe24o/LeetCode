class Solution {
    unordered_map<TreeNode*, int> pos;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        dfs(root,0);
        int pt, pi, dis = 0;
        for(auto posi : pos)
        {
            pt = pos[target];
            pi = posi.second;
            dis = 0;
            while(pt != pi)
            {
                if(pt < pi)
                    pi = (pi-1)/2;
                else
                    pt = (pt-1)/2;
                dis++;
            }
            if(dis == K)
                ans.push_back(posi.first->val);
        }
        return ans;
    }
    void dfs(TreeNode* root, int p)
    {
        if(!root) return;
        pos[root] = p;
        dfs(root->left, 2*p+1);
        dfs(root->right, 2*p+2);
    }
};

class Solution {
    unordered_map<TreeNode*, TreeNode*> f;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, NULL);
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int dis = 0, size;
        TreeNode* tp;
        while(!q.empty())
        {
            if(dis == K)
                break;
            size = q.size();
            while(size--)
            {
                tp = q.front();
                q.pop();
                if(tp->left && !visited.count(tp->left))
                {
                    q.push(tp->left);
                    visited.insert(tp->left);
                }
                if(tp->right && !visited.count(tp->right))
                {
                    q.push(tp->right);
                    visited.insert(tp->right);
                }
                if(f[tp] && !visited.count(f[tp]))
                {
                    q.push(f[tp]);
                    visited.insert(f[tp]);
                }
            }
            dis++;
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
    void dfs(TreeNode* root, TreeNode* father)
    {
        if(!root) return;
        f[root] = father;
        dfs(root->left, root);
        dfs(root->right, root);
    }
};