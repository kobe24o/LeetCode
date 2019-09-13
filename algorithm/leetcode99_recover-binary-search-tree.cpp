class Solution {
public:
    void recoverTree(TreeNode* root) {
    	if(root == NULL)
    		return;
        TreeNode *node1 = NULL, *node2 = NULL, *prev = NULL;
       	stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
        	while(root)
        	{
        		stk.push(root);
        		root = root-> left;
        	}
        	root = stk.top();	
        	if(prev && prev->val > root->val)
        	{
        		node1 = node1 ? node1 : prev;//node1只被赋值一次
        		node2 = root;//被交换的数相邻，node2只赋值一次，否则2次
        	}
        	prev = root;
        	root = stk.top()->right;
        	stk.pop();
        }
        swap(node1->val, node2->val);
    }
};