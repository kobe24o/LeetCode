class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void preorder(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        preorder(root->left, ans);
        preorder(root->right, ans);
        ans.push_back(root->val);
    }
};

// stk1，模仿前序遍历的实现“反后序遍历”
// stk2，保存stk1的pop元素
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);
        TreeNode *cur;
        while(!stk1.empty())
        {
            cur = stk1.top();
            stk1.pop();
            stk2.push(cur);
            if(cur->left)
                stk1.push(cur->left);
            if(cur->right)
                stk1.push(cur->right);
        }
        while(!stk2.empty())
        {
            cur = stk2.top();
            stk2.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};

// 先按照"根-右-左"的顺序遍历二叉树(和先序遍历有些像)，
// 然后将遍历的结果反转过来就是“左-右-根”，也就是后序遍历了
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                ans.push_back(root->val);
                root = root->right;
            }
            root = stk.top()->left;
            stk.pop();
        }
        //反转遍历结果
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        TreeNode *cur;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            cur = stk.top();
            if(cur->left)
            {
                stk.push(cur->left);
                cur->left = NULL;
            }
            else if(cur->right)
            {
                stk.push(cur->right);
                cur->right = NULL;
            }
            else
            {
                ans.push_back(cur->val);
                stk.pop();
            }
        }
        return ans;
    }
};
