class TrieNode
{
public:
	TrieNode *next[26];
	int count;
	TrieNode():count(0)
	{
		memset(next,NULL,26*sizeof(TrieNode*));
	}
	~TrieNode(){}
};

class MapSum {
	TrieNode *root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *cur = root;
        for(char ch:key)
        {
        	if(cur->next[ch-'a'] == NULL)
    			cur->next[ch-'a'] = new TrieNode();
			cur = cur->next[ch-'a'];
        }
    	cur->count = val;
    }
    
    int sum(string prefix) {
        TrieNode *cur = root;
        for(char ch:prefix)
        {
        	if(cur->next[ch-'a'] == NULL)
        		return 0;
        	else
        		cur = cur->next[ch-'a'];
        }
    	int sumVal = 0;
    	sumVal += cur->count;
    	for(int i = 0; i < 26; ++i)
    		if(cur->next[i])
    			sumVal += sum(cur->next[i]);
		return sumVal;
    }
private:
	int sum(TrieNode *root)//递归求和
	{
		int subsum = 0;
		if(root == NULL)
			return 0;
		subsum += root->count;
		for(int i = 0; i < 26; ++i)
			if(root->next[i])
				subsum += sum(root->next[i]);
		return subsum;
	}    	
};