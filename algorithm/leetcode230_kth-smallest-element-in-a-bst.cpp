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
public:
    int kthSmallest(TreeNode* root, int k) {
    	int i = 0, ans;
    	bool found = false;
        findkth(root,k,i,ans,found);
        return ans;
    }

    void findkth(TreeNode* &root, int &k, int &i, int &ans, bool &found)
    {
    	if(root == NULL || found)
    		return;
    	findkth(root->left,k,i,ans,found);
    	i++;
    	if(i == k)
		{
			ans = root->val;
			found = true;
		}
    	findkth(root->right,k,i,ans,found);
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
		int ans,count = 0;
		stack<TreeNode*> stk;
		while(root || !stk.empty())
		{
			while(root)
			{
				stk.push(root);
				root = root->left;
			}
			if(!stk.empty())
			{
				root = stk.top();
				stk.pop();
				if(++count == k)
					return root->val;
				root = root->right;
			}
		}
		return -1;
	}
};