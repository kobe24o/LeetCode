class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
    	int p1 = -1, p2 = -1, mindis = INT_MAX;
    	for(int i = 0; i < words.size(); ++i)
    	{
            if(word1 == word2 && words[i] == word1)
            {
                if(p1 != -1)
                    mindis = min(mindis, i-p1);
                p1 = i;
                continue;
            }
    		if(words[i] == word1)
    			p1 = i;
    		if(words[i] == word2)
    			p2 = i;
    		if(p1 != -1 && p2 != -1)
    			mindis = min(mindis, abs(p1-p2));
    	}
    	return mindis;
    }
};