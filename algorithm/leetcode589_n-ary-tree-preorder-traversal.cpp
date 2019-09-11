/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preRec(root,ans);
        return ans;
    }
    void preRec(Node* root, vector<int> &ans) 
    {
    	if(root == NULL)
    		return;
    	ans.push_back(root->val);
    	for(int i = 0; i < root->children.size(); ++i)
    		preRec(root->children[i], ans);
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == NULL)
            return {};
        vector<int> ans;
        stack<Node*> stk;
        Node *tp;
        int i;
        stk.push(root);
        while(!stk.empty())
        {
            tp = stk.top();
    		ans.push_back(tp->val);
    		i = tp->children.size();
    		stk.pop();
        	while(i)
        	{
				stk.push(tp->children[--i]);
        	}
        }
        return ans;
    }
};