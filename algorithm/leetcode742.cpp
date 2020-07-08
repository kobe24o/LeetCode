class Solution {
	unordered_map<TreeNode*,TreeNode*> father;
	queue<TreeNode*> q;
	unordered_set<TreeNode*> visited;
public:
    int findClosestLeaf(TreeNode* root, int k) {
    	father[root] = NULL;
    	dfs(root, k);
    	int size;
    	TreeNode* cur;
    	while(!q.empty())
    	{
    		size = q.size();
    		while(size--)
    		{
    			cur = q.front();
    			q.pop();
    			if(!cur->left && !cur->right)
    				return cur->val;
    			if(cur->left && !visited.count(cur->left))
    			{
    				q.push(cur->left);
    				visited.insert(cur->left);
    			}
    			if(cur->right && !visited.count(cur->right))
    			{
    				q.push(cur->right);
    				visited.insert(cur->right);
    			}
    			if(father[cur] && !visited.count(father[cur]))
    			{
    				q.push(father[cur]);
    				visited.insert(father[cur]);
    			}
    		}
    	}
    	return -1;
    }
    void dfs(TreeNode* root, int k) 
    {
    	if(!root) return;
    	if(root->val == k)
    	{
    		q.push(root);
    		visited.insert(root);
    	}
    	if(root->left)
    		father[root->left] = root;
    	if(root->right)
    		father[root->right] = root;
    	dfs(root->left,k);
    	dfs(root->right,k);
    }
};