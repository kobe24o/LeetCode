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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postRec(root, ans);
        return ans;
    }

    void postRec(Node* root, vector<int> &ans)
    {
    	if (root == NULL)
    		return;
    	for(int i = 0; i < root->children.size(); ++i)
    	{
    		postRec(root->children[i], ans);
    	}
    	ans.push_back(root->val);
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL)
        	return {};
        vector<int> ans;
        stack<Node*> stk;
        stk.push(root);
        Node *tp;
        int i, k;
        while(!stk.empty())
        {
        	tp = stk.top();
        	k = tp->children.size();
        	ans.push_back(tp->val);
        	stk.pop();
        	i = 0;
        	while(i<k)
        		stk.push(tp->children[i++]);
        }
        //上面得到的是根右左，逆序return得到左右根(后序)
        return vector<int> (ans.rbegin(), ans.rend());
    }
};