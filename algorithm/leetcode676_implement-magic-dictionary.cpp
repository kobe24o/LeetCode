class MagicDictionary {
	unordered_set<string> origin;
	unordered_set<int> len;
	string temp;
	int i;
	char ch;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string& word : dict) 
        {
        	origin.insert(word);
        	len.insert(word.length());
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
    	if(!len.count(word.length()))
    		return false;
    	for(i = 0; i < word.size(); ++i)
    	{
    		temp = word;
    		for(ch = 'a'; ch <= 'z'; ++ch)
    		{
    			temp[i] = ch;
    			if(origin.count(temp) && temp != word)
    				return true;
    		}	
    	}
        return false;
    }
};