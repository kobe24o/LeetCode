class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        TreeNode *tp;
        q.push(root);
        int n;
        bool xOccur = false, yOccur = false;
        while(!q.empty())
        {
        	n = q.size();
        	while(n--)//这个循环内是一层的节点
        	{
	        	tp = q.front();
	        	q.pop();
	        	//如果都属于一个父节点，false
	        	if((tp->left && tp->right) && ((tp->left->val == x && tp->right->val == y)
	        		|| (tp->left->val == y && tp->right->val == x)))
	        		return false;
	        	if(tp->val == x)
	        		xOccur = true;
	        	if(tp->val == y)
	        		yOccur = true;
	        	if(tp->left)
	        		q.push(tp->left);
	        	if(tp->right)
	        		q.push(tp->right);
	        }
	        //这一层结束了，检查x，y的出现状态
	        if((xOccur^yOccur) == 1)//只有一个出现过了，说明不在一层
	        	return false;
	        else if(xOccur && yOccur)//都出现了
	        	return true;
        }
        return false;
    }
};

class Solution {	
public:
    bool isCousins(TreeNode* root, int x, int y) {
    	if(root->val = x || root->val == y)
    		return false;
    	TreeNode *pX = NULL, *pY = NULL;//x,y节点的父节点
		int depX = 0, depY = 0;//x,y节点的深度
		bool found = false;
        findXY(root,x,0,found,pX,depX);
        found = false;
        findXY(root,y,0,found,pY,depY);
        if((pX != pY) && (depX == depY))
        	return true;
        return false;
    }

    void findXY(TreeNode* root, int &v, int dep, bool &found, TreeNode* &parent, int &depXY)
    {
    	if(root == NULL || found)
    		return;
    	if((root->left && root->left->val == v)
    			|| (root->right && root->right->val == v))
    	{
    		parent = root;
    		depXY = dep;
    		found = true;
    		return;
    	}
    	findXY(root->left,v,dep+1,found,parent,depXY);
    	findXY(root->right,v,dep+1,found,parent,depXY);
    }
};