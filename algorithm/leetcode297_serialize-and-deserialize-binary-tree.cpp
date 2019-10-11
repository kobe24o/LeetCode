class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
	    if(root == NULL) 
	    	return "";
	    queue<TreeNode*> q;
	    TreeNode* node;
	    q.push(root);
	    ostringstream out;
	    while(!q.empty())
	    {
    	    node = q.front();
            q.pop();
            if(node == NULL)   
                out << "N ";
            else
            {
                out << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
	    }  
    	return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())    
        	return NULL;
	    istringstream in(data);
	    string s;
	    in >> s;
	    TreeNode* root = new TreeNode(stoi(s));	    
	    queue<TreeNode*> q;
	    TreeNode* node;
	    q.push(root);	    
	    while(!q.empty())
	    {
	        node = q.front();
	        q.pop();
	        in >> s;
	        if(s[0] == 'N')
	            node->left = NULL;
	        else
	        {
	            node->left = new TreeNode(stoi(s));
	            q.push(node->left);
	        }
	        
	        in >> s;
	        if(s[0] == 'N')
	            node->right = NULL;
	        else
	        {
	            node->right = new TreeNode(stoi(s));
	            q.push(node->right);
	        }
	        
	    } 
	    return root;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root,ostringstream &out)
    {
        if(root)
        {
            out<< root->val << ' ';
            serialize(root->left,out);
            serialize(root->right,out);
        }
        else
            out << "N ";  
    }
    TreeNode* deserialize(istringstream &in)
    {
        string val;
        in >> val;
        if(val == "N"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};