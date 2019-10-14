class Trie
{
private:
    bool isEnd = false;
    Trie* next[26] = { nullptr };
public:
    Trie() {}

    void insert(const string& word)//插入单词
    {
        Trie* root = this;
        for (const auto& w : word) {
            if (root->next[w-'a'] == nullptr)
                root->next[w-'a'] = new Trie();
            root = root->next[w-'a'];
        }
        root->isEnd = true;
    }

    bool search(const string& word)//查找单词
    {
        Trie* root = this;
        for (const auto& w : word) {
            if (root->next[w-'a'] == nullptr)
                return false;
            root = root->next[w-'a'];
        }
        return root->isEnd;
    }

    bool startsWith(string prefix)//查找前缀
    {
        Trie* root = this;
        for (const auto& p : prefix) {
            if (root->next[p-'a'] == nullptr)
                return false;
            root = root->next[p-'a'];
        }
        return true;
    }
};