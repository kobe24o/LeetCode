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
	int mins = 0;
public:
    int minCameraCover(TreeNode* root) {
    	if(!root) return 0;
    	int l = dfs(root);
    	if(l == 0)
            mins++;
        return mins;
    }

    int dfs(TreeNode* root)
    {   // 1表示被监控，但是实际没有camera
        // 2表示被监控，有camera
        // 0 表示需要被监控
    	if(!root)
    		return 1;//没有节点了相当于监控了
    	int l = dfs(root->left);
    	int r = dfs(root->right);
    	
    	if(l==0 || r==0)//5种情况
    	{
    		mins++;//左右子节点有任意一个需要被监控
    		return 2;//节点安装摄像头
    	}
        else if(l==1 && r==1)//1种情况，左右子节点都被监控了
    		return 0;//本节点无须安装，但是需要被监控
        else//12，21，22
        {   // 左右子节点有任一为2（摄像头）
            return 1;//节点处于被监控状态
        }
    }
};