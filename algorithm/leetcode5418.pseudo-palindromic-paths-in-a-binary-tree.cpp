class Solution {
	int count = 0;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return count;
    }
    void dfs(TreeNode* root, int state)
    {
        int m = root->val;
    	if((state>>m)&1)//为1
    		state &= ~(1<<m);//改为0
    	else
    		state |= (1<<m);//该位是0，则改为1

    	if(!root->left && !root->right)
    	{
    		int odd = 0;
    		for(int i = 1; i <= 9; ++i)
    			if((state>>i)&1)
    				odd++;
			if(odd <= 1)
				count++;
    		return;
    	}
    	
        if(root->left)
    	    dfs(root->left, state);
    	if(root->right)
            dfs(root->right, state);
    }
};