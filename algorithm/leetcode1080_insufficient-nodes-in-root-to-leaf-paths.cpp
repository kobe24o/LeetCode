#include<string>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	int sum = 0;
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
    	if(!root)
    		return NULL;
    	sum += root->val;
    	if(!root->left && !root->right)//叶子节点
    	{
    		if(sum < limit)//需要删除节点
    		{
    			sum -= root->val;
    			return NULL;//一会父节点left或right指向nullptr
    		}
    		else
    		{
    			sum -= root->val;
    			return root;
    		}
    	}
    	else	//非叶子节点，继续往下+
    	{
    		root->left = sufficientSubset(root->left, limit);
    		root->right = sufficientSubset(root->right, limit);
    		sum -= root->val;
    		if(!root->left && !root->right)
    			return NULL;
    		else
    			return root;
    	}
    }
};

int main()
{
	TreeNode *root = new TreeNode(0);
    TreeNode *l1= new TreeNode(1);
    TreeNode *l2 = new TreeNode(2);
    TreeNode *l3 = new TreeNode(-2);
    TreeNode *l4 = new TreeNode(-1);
    TreeNode *l5 = new TreeNode(-5);
    TreeNode *l6 = new TreeNode(1);
	root->left = l1;root->right = l2;
	l1->left = l3;l1->right = l4;
	l2->left = l5;l2->right = l6;
	Solution s;
	s.sufficientSubset(root,1);
}