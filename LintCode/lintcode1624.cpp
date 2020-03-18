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
    int maxlen = 0;
public:
    int getAns(vector<string> &s) {
        trieTree t;
        for(string& si : s)
            t.insert(si);
        dfs(t.root, 0);
        return maxlen;
    }

    int dfs(trie* root, int count)
    {
        if(!root)
            return 0;
        if((root->left && root->right) || root->isend)
        {
            int l = height(root->left);
            int r = height(root->right);
            maxlen = max(maxlen,r+l);
        }
        dfs(root->left,count+1);
        dfs(root->right,count+1);
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