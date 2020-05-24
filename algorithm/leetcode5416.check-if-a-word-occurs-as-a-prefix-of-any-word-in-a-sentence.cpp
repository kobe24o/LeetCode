class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
    	istringstream in(sentence);
    	string s;
    	int idx = 1;
    	while(in >> s)
    	{
    		if(s.find(searchWord) == 0)
    			return idx;
    		idx++;
    	}
    	return -1;
    }
};