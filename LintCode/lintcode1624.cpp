class trie
{
public:
    char ch;
    trie* left;
    trie* right;
    bool isend;
    trie(char c)
    {
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
    int sum = 0;
public:
    int getAns(vector<string> &s) {
        trieTree t;
        for(string& si : s)
            t.insert(si);

        dfs(t.root);
        return sum;
    }

    int dfs(trie* root)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        else if(root->left && !root->right)
            return dfs(root->left);
        else if(!root->left && root->right)
            return dfs(root->right);
        else if(root->left && root->right)
        {
            int l = dfs(root->left)+1;
            int r = dfs(root->right)+1;
            sum = max(sum, l+r);
            return max(l,r);
        }

    }
};