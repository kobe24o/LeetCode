class Solution {
	unordered_set<int> s;
	vector<TreeNode*> ans;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    	if(!root)
    		return {};
    	for(int del : to_delete)
    		s.insert(del);//哈希快速查找
    	order(root, NULL, 0);
    	return ans;
    }

    void order(TreeNode* root, TreeNode* father, int dir)
    {	//参数，当前节点，其父节点，是父节点的左节点还是右节点
    	if(!root)
    		return;
    	if(s.count(root->val))//root需要删除
    	{
    		if(father)//要删除的节点有父节点
    		{
    			if(dir==0)//是左边过来的
    				father->left = NULL;//断开与父节点的链接
    			else
    				father->right = NULL;
    		}
    		TreeNode *l = root->left, *r = root->right;//当前节点的左右子节点
    		root->left = NULL;//断开子的链接
    		root->right = NULL;//断开子的链接
    		order(l, NULL, 0);//遍历左子，其父节点断开了，为空，第三个参数随意
    		order(r, NULL, 0);//遍历右子
    	}
    	else//root不用删除
    	{
            if(!father)//如果没有父节点了,新的树根，加入答案
    		    ans.push_back(root);
    		order(root->left, root, 0);//遍历左子，第三个参数0表示左
    		order(root->right, root, 1);//遍历右子，第三个参数1表示右
    	}
    }
};