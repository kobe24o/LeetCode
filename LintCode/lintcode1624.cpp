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
    bool found = false;
    trie *node = NULL;
public:
    int getAns(vector<string> &s) {
        trieTree t;
        for(string& si : s)
            t.insert(si);

        dfs(t.root,0);
        int l = findpath(node->left);
        int r = findpath(node->right);
        return l+r;
    }

    void dfs(trie* root, int count)
    {
        if(!root)
            return;
        if((root->left && root->right) )
        {
            found = true;
            node = root;
            return;
        }
        if((root->isend && root->left) || (root->isend && root->right))
        {
            node = root;
        }
        dfs(root->left,count+1);
        dfs(root->right,count+1);
    }

    int findpath(trie* root)
    {
        if(!root)
            return 0;
        int l = findpath(root->left);
        int r = findpath(root->right);
        return max(l,r)+1;
    }
};

["01","10","0","1","1001010"]
["01","0","0101010"]  6
["011000","0111010","01101010"] 9
["011000","0111011","01001010"] 11