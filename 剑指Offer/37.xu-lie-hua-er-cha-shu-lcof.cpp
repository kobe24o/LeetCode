class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	string s;
        serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	istringstream in(data);
        return deserialize(in);
    }
private:
	void serialize(TreeNode* root, string& s)
	{
		if(!root)
		{
			s += "N ";
			return;
		}
		s += to_string(root->val)+' ';
		serialize(root->left, s);
		serialize(root->right, s);
	}

	TreeNode* deserialize(istringstream& in)
	{
		string s;
		in >> s;
		if(s == "N")
			return NULL;
		TreeNode *root = new TreeNode(stoi(s));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
};