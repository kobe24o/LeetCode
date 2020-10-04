class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool desc = false;//降序？（初始0层，是升序）
        while(!q.empty()) 
        {
            int size = q.size();
            int cur, prev = desc ? INT_MAX : -1;
            while(size--)
            {
                cur = q.front()->val;
                if(cur%2 == 1 && desc)
                    return false;
                if(cur%2==0 && !desc)
                    return false;
                if(cur==prev || (cur > prev && desc)||(cur < prev && !desc))
                    return false;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
                prev = cur;
            }
            desc = !desc;
        }
        return true;
    }
};