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
	map<int, vector<pair<int,int>>> ans;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for(auto& a : ans)
        {
        	sort(a.second.begin(), a.second.end(),[&](auto a, auto b){
                return a.first < b.first;
            });
            vector<int> temp;
            for(auto& d_val : a.second)
                temp.push_back(d_val.second);
        	res.push_back(temp);
        }
        return res;
    }
    void dfs(TreeNode* root, int x, int deep)
    {
    	if(!root) return;
    	ans[x].push_back({deep, root->val});
    	dfs(root->left, x-1, deep+1);
    	dfs(root->right, x+1, deep+1);
    }
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
    	if(!root) return {};
        vector<vector<int>> res;
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        int size, x, val;
        TreeNode *cur;
        q.push({root, 0});
        while(!q.empty())
        {
        	size = q.size();
        	while(size--)
        	{
                cur = q.front().first;
        		val = cur->val;
        		x = q.front().second;
                q.pop();
        		m[x].push_back(val);
        		if(cur->left)
        			q.push({cur->left, x-1});
        		if(cur->right)
        			q.push({cur->right, x+1});
        	}
        }
        for(auto& mi : m)
            res.push_back(mi.second);
        return res;
    }
};