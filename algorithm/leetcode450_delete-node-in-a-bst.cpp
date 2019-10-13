class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
    	TreeNode *parent = NULL, *cur = root;
        while(cur && cur->val != key)
        {
        	parent = cur;
        	if(cur->val < key)
        		cur = cur->right;
        	else
        		cur = cur->left;
        }
        if(cur == NULL)
        	return root;
        if(cur->left != NULL && cur->right != NULL)
        {//要删除的节点有2个子节点，找到右子树最小的换上去，在删除
        	TreeNode *minP = cur->right, *minPfather = cur;
        	while(minP->left)
        	{
        		minPfather = minP;
        		minP = minP->left;
        	}
        	cur->val = minP->val;
        	cur = minP;//要删除的cur
        	parent = minPfather;
        }
        //要删除的节点有1个或0个子节点
    	TreeNode *child;
    	if(cur->left)
    		child = cur->left;
    	else if(cur->right)
    		child = cur->right;
    	else
    		child = NULL;
    	if(parent == NULL)//要删的是根节点
    		root = child;
    	else if(cur == parent->left)
    		parent->left = child;
    	else
    		parent->right = child;
        return root;
    }
};