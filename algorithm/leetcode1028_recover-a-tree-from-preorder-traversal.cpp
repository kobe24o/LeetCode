class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int depth = 0, i = 0, val = 0;
        stack<pair<TreeNode*,int>> stk;
        TreeNode *root, *cur;
        val = getVal(S,i);
        root = new TreeNode(val);
        stk.push(make_pair(root,0));
        while(i < S.size())
        {
        	depth = getDep(S,i);
        	val = getVal(S,i);
        	cur = new TreeNode(val);
        	while(stk.top().second >= depth)
        		stk.pop();
        	if(stk.top().first->left)
        		stk.top().first->right = cur;
        	else
        		stk.top().first->left = cur;
        	stk.push(make_pair(cur,depth));
        }
        return root;
    }

    int getVal(string &S, int &i)
    {
    	int val = 0;
    	while(i < S.size() && isdigit(S[i]))
    		val = val*10+S[i++]-'0';
    	return val;
    }
    int getDep(string &S, int &i)
    {
    	int depth = 0;
    	while(S[i] == '-')
    	{
    		depth++;
    		i++;
    	}
    	return depth;
    }
};