class Solution {
public:
    int maxDepth(Node* root) {
    	if(root == NULL)
    		return 0;
    	int childDep = 0;
    	for(int i = 0; i < root->children.size(); ++i)
    	{
    		childDep = max(childDep, maxDepth(root->children[i]));
    	}
		return childDep+1;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
    	if(root == NULL)
    		return 0;
    	int deep = 0;
    	queue<Node*> q;
    	Node *tp;
    	q.push(root);
    	int n, i;
    	while(!q.empty())
    	{
    		++deep;
    		n = q.size();
    		while(n--)
    		{
    			tp = q.front();
    			for(i = 0; i < tp->children.size(); ++i)
    				q.push(tp->children[i]);
    			q.pop();
    		}
    	}
    	return deep;
    }
};