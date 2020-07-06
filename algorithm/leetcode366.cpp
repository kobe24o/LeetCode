class Solution {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    unordered_map<TreeNode*, int> map;//父节点底下挂着几个子节点
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        reverse(root);
        while(!q.empty())
        {
        	int size = q.size(), i = 0;
        	vector<int> lv(size);
        	while(size--)
        	{
        		TreeNode *cur = q.front();
        		q.pop();
        		map[cur->left]--;
        		lv[i++] = cur->val;
        		if(cur->left && map[cur->left]==0)
        			q.push(cur->left);
        	}
        	ans.push_back(lv);
        }
        return ans;
    }
    TreeNode* reverse(TreeNode* root)
    {
    	if(!root) return NULL;
    	auto l = root->left;
    	auto r = root->right;
    	if(!l && !r)
    		q.push(root);
    	map[root] += (l?1:0) + (r?1:0);//记得加括号
    	root->left = NULL;
    	root->right = NULL;
    	auto lc = reverse(l);
    	auto rc = reverse(r);
    	if(lc)
    		lc->left = root;
    	if(rc)
    		rc->left = root;
    	return root;
    }
};