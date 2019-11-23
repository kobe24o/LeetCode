class FindElements {
	unordered_set<int> s;
public:
    FindElements(TreeNode* root) {
        dfs(root,0);
    }

    void dfs(TreeNode* root, int val)
    {
    	if(root == NULL)
    		return;
    	s.insert(val);
    	dfs(root->left,(val<<1)+1);
    	dfs(root->right,(val<<1)+2);
    }
    
    bool find(int target) {
        return s.count(target);
    }
};

class FindElements {
	unordered_set<int> s;
public:
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        pair<TreeNode*,int> tp;
        while(!q.empty())
        {
        	tp = q.front();
        	q.pop();
        	s.insert(tp.second);
        	if(tp.first->left)
        		q.push(make_pair(tp.first->left, (tp.second<<1)+1));
        	if(tp.first->right)
        		q.push(make_pair(tp.first->right, (tp.second<<1)+2));
        }
    }

    bool find(int target) {
        return s.count(target);
    }
};