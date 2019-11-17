class CBTInserter {
	TreeNode *r = NULL;
	vector<TreeNode*> insertNode;//存储原始树的各个节点
	int i, fatherVal;
	queue<TreeNode*> upperLv;//存储完全二叉树子节点没插满的节点
	TreeNode *tp;
public:
    CBTInserter(TreeNode* root) {
        lvOrder(root);//树节点层序添加进数组，并拆散，待用
        if(r == NULL)
        {
        	r = insertNode.front();
        	insertNode.erase(insertNode.begin());
        	upperLv.push(r);
        }
        while(!insertNode.empty())
        {
        	tp = insertNode.front();
        	insertNode.erase(insertNode.begin());
        	upperLv.push(tp);//tp的子节点没有满
        	if(upperLv.front()->left == NULL)
        		upperLv.front()->left = tp;
        	else//左边接上了，接在右边
        	{
        		upperLv.front()->right = tp;
        		upperLv.pop();//左右都接好了，上层的可以删了
        	}
        }
    }
    
    int insert(int v) {
    	fatherVal = upperLv.front()->val;
    	tp = new TreeNode(v);
        if(upperLv.front()->left == NULL)
    		upperLv.front()->left = tp;
    	else//左边接上了，接在右边
    	{
    		upperLv.front()->right = tp;
    		upperLv.pop();//左右都接好了，上层的可以删了
    	}
    	upperLv.push(tp);//tp的子节点没有满
    	return fatherVal;
    }
    
    TreeNode* get_root() {
        return r;
    }

    void lvOrder(TreeNode *root)
    {
    	if(root == NULL)
    		return;
    	insertNode.clear();
    	insertNode.push_back(root);
    	for(i = 0; i < insertNode.size(); ++i)
    	{
    		if(insertNode[i]->left)
    			insertNode.push_back(insertNode[i]->left);
    		if(insertNode[i]->right)
    			insertNode.push_back(insertNode[i]->right);
    		insertNode[i]->left = insertNode[i]->right = NULL;//拆散整棵树后面直接利用，节省内存
    	}
    }
};