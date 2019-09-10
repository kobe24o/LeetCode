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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
        	return {};
        vector<vector<int>> ans;
        vector<int> lv;
        int Num, i;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
        	lv.clear();
        	Num = q.size();
        	while(Num--)
        	{
        		lv.push_back(q.front()->val);
        		for(i = 0; i < q.front()->children.size(); ++i)
        			q.push(q.front()->children[i]);
        		q.pop();
        	}
        	ans.push_back(lv);
        }
        return ans;
    }
};