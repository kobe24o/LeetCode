class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<double> ans;
        int Num, n;
        long lvsum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            lvsum = 0;
            n = Num = q.size();
            while(Num--)
            {
                lvsum += q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(double(lvsum)/n);
        }
        return ans;
    }
};