class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        int sum, n;
        q.push(root);
        while(!q.empty())
        {
            n = q.size();
            sum = 0;
            while(n--)
            {
                sum += q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }
        return sum;
    }
};