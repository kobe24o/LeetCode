#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        int maxcount = 0;
//        if(root)
//        {
//            calcTreeDepth(root, 0, maxcount);
//        }
//        return maxcount;
//    }
//    void calcTreeDepth(TreeNode* root, int height, int &maxcount)
//    {
//        if(root)
//        {
//            height++;
//            if(height > maxcount)
//                maxcount = height;
//            if(root->left)
//                calcTreeDepth(root->left, height, maxcount);
//            if(root->right)
//                calcTreeDepth(root->right, height, maxcount);
//        }
//    }
//};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxcount = 0, i, n;
        while(!q.empty())
        {
            ++maxcount;
            n = q.size();
            for(i = 0; i < n; ++i)
            {
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return maxcount;
    }
};