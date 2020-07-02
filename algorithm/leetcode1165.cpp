class Solution {
public:
    int calculateTime(string keyboard, string word) {
    	unordered_map<char,int> m;
    	for(int i = 0; i < 26; ++i)
    		m[keyboard[i]] = i;
    	int dis = 0;
    	char prev = 0;
    	for(int i = 0; i < word.size(); ++i)
    	{
    		dis += abs(m[word[i]]-prev);
    		prev = m[word[i]];
    	}
    	return dis;
    }	
};