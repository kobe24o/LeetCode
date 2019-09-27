/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
	bool visited[101] = {0};
public:
    Node* cloneGraph(Node* node) {
    	unordered_map<int, Node*> m;//新节点值和它自己的指针
    	unordered_map<Node*, vector<int>> nhb;//一个节点值对应的邻居的节点值
    	queue<Node*> q;
    	q.push(node);
    	Node *root, *ans;
    	visited[node->val] = 1;
    	int i = -1, n;
    	while(!q.empty())
    	{
    		n = q.front()->neighbors.size();
    		root = new Node(q.front()->val, vector<Node*> {});
    		if(i == -1)
    			ans = root;
    		m[q.front()->val] = root;
    		for(i = 0; i < n; i++)
    		{
    			nhb[root].push_back(q.front()->neighbors[i]->val);
    			if(!visited[q.front()->neighbors[i]->val])
    			{
    				q.push(q.front()->neighbors[i]);
    				visited[q.front()->neighbors[i]->val] = 1;
    			}
    		}
    		q.pop();
    	}
        for(auto it = nhb.begin(); it != nhb.end(); ++it)
        {
        	n = it->second.size();
        	for(i = 0; i < n; i++)
        	{
        		it->first->neighbors.push_back(m[it->second[i]]);
        	}
        }
        return ans;
    }
};
class Solution {
	Node* visited[101] = {NULL};
public:
    Node* cloneGraph(Node* node) {
        int size = node->neighbors.size();
        Node *root = new Node(node->val, vector<Node*> {});
        visited[node->val] = root;
        for (int i = 0; i < size; i++) {
            if (!visited[node->neighbors[i]->val])
                root->neighbors.push_back(cloneGraph(node->neighbors[i]));
            else
                root->neighbors.push_back(visited[node->neighbors[i]->val]);
        }
        return root;
    }
};