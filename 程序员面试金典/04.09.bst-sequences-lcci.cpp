class Solution {
	vector<vector<int>> ans;
	vector<int> temp;
	deque<TreeNode*> q;
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
    	if(!root)
    		return {{}};
    	q.push_back(root);
    	dfs();
    	return ans;
    }

    void dfs()
    {
    	if(q.empty())
    	{
    		ans.push_back(temp);
    		return;
    	}
    	int size = q.size();
    	while(size--)
    	{
    		TreeNode *tp = q.front();
    		q.pop_front();	//现场，BFS队列里的节点
    		temp.push_back(tp->val);
    		int children = 0;
    		if(tp->left)
    		{
    			q.push_back(tp->left);
    			children++;
    		}
    		if(tp->right)
    		{
    			q.push_back(tp->right);
    			children++;
    		}
    		dfs();
    		while(children--)
    			q.pop_back();
    		q.push_back(tp);//恢复现场
    		temp.pop_back();
    	}
    }
};