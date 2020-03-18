class trie
{
public:
    char ch;
    trie* left;
    trie* right;
    bool isend;
    trie(char c)
    {
        ch = c;
        left = right = NULL;
        isend = false;
    }
};

class trieTree
{
public:
    trie *root;
    trieTree(){
        root = new trie('*');
    }
    void insert(string s)
    {
        trie* cur = root;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '0')
            {
                if(!cur->left)
                    cur->left = new trie('0');
                cur = cur->left;
            }
            else
            {
                if(!cur->right)
                    cur->right = new trie('1');
                cur = cur->right;
            }
        }
        cur->isend = true;
    }

};

class Solution {
    bool found = false;
    trie *node = NULL;
public:
    int getAns(vector<string> &s) {
        trieTree t;
        for(string& si : s)
            t.insert(si);

        dfs(t.root);
        int l = height(node->left);
        int r = height(node->right);
        return l+r;
    }

    void dfs(trie* root)
    {
        if(!root)
            return;
        if((root->left && root->right) || root->isend)
        {
            found = true;
            node = root;
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }

    int height(trie* root)
    {
        if(!root)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        return max(l,r)+1;
    }
};