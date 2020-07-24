/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int ans = 0;
public:
    int diameter(Node* root) {
        h(root);
        return ans;
    }
    int h(Node* root)
    {
        if(!root) return 0;
        int maxdep1 = 0, maxdep2 = 0, height;
        for(auto c : root->children)
        {
            height = h(c);
            if(height >= maxdep1)
            {
                maxdep2 = maxdep1;
                maxdep1 = height;
            }
            else if(height > maxdep2)
                maxdep2 = height;
        }
        ans = max(ans, maxdep2+maxdep1);
        return max(maxdep1, maxdep2) + 1;
    }
};
