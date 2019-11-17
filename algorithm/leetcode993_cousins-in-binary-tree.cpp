// class Solution {
// public:
//     bool isCousins(TreeNode* root, int x, int y) {
//         queue<TreeNode*> q;
//         TreeNode *tp;
//         q.push(root);
//         int n;
//         bool xOccur = false, yOccur = false;
//         while(!q.empty())
//         {
//         	n = q.size();
//         	while(n--)//这个循环内是一层的节点
//         	{
// 	        	tp = q.front();
// 	        	q.pop();
// 	        	//如果都属于一个父节点，false
// 	        	if((tp->left && tp->right) && ((tp->left->val == x && tp->right->val == y)
// 	        		|| (tp->left->val == y && tp->right->val == x)))
// 	        		return false;
// 	        	if(tp->val == x)
// 	        		xOccur = true;
// 	        	if(tp->val == y)
// 	        		yOccur = true;
// 	        	if(tp->left)
// 	        		q.push(tp->left);
// 	        	if(tp->right)
// 	        		q.push(tp->right);
// 	        }
// 	        //这一层结束了，检查x，y的出现状态
// 	        if((xOccur^yOccur) == 1)//只有一个出现过了，说明不在一层
// 	        	return false;
// 	        else if(xOccur && yOccur)//都出现了
// 	        	return true;
//         }
//         return false;
//     }
// };
// 
class Solution {    
    TreeNode *pX = NULL, *pY = NULL;//x,y节点的父节点
    int depX = 0, depY = 0;//x,y节点的深度
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)
            return false;
        findXY(root,x,y,0);
        if((pX != pY) && (depX == depY))
            return true;
        return false;
    }

    void findXY(TreeNode* root, int &x, int &y, int dep)
    {
        if(root == NULL)
            return;
        if((root->left && (root->left->val == x))
                || (root->right && (root->right->val == x)))
        {
            pX = root;
            depX = dep;
        }
        if((root->left && (root->left->val == y))
                || (root->right && (root->right->val == y)))
        {
            pY = root;
            depY = dep;
        }
        findXY(root->left,x,y,dep+1);
        findXY(root->right,x,y,dep+1);
    }
};