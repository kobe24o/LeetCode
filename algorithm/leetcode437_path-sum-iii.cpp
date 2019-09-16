class Solution {
	int count = 0;
public:
    int pathSum(TreeNode* root, int sum) {
    	if(root == NULL)
    		return 0;
        pathSum(root->left,sum);//以root->left节点从新开始
        pathSum(root->right,sum);
        add(root,sum,0);
        return count;
    }
    void add(TreeNode* root, int &sum, int cursum) 
    {
    	if(root == NULL)
    		return;
    	if(cursum+root->val == sum)
    		++count;
		add(root->left,sum,cursum+root->val);
		add(root->right,sum,cursum+root->val);
    }
};