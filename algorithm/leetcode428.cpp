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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) 
    {
        ostringstream out;
        serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) 
    {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(Node* root,ostringstream &out)
    {
        if(root)
        {
            out<< root->val << ' ';
            out<< root->children.size() << ' ';
            for(auto p : root->children)
                serialize(p, out);
        }
        else
            out << "N ";  
    }
    Node* deserialize(istringstream &in)
    {
        string val;
        in >> val;
        if(val == "N"){
            return NULL;
        }
        Node* root = new Node(stoi(val));
        in >> val;
        int n = stoi(val);
        while(n--)
        {
            Node* p = deserialize(in);
            root->children.push_back(p);
        }
            
        return root;
    }
};