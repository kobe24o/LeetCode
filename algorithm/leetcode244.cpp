class WordDistance {
    unordered_map<string,set<int>> m;
public:
    WordDistance(vector<string>& words) {
    	for(int i = 0; i < words.size(); ++i)
        {
            m[words[i]].insert(i);
        }
    }
    
    int shortest(string word1, string word2) {
    	int mindis = INT_MAX;
    	for(auto i = m[word1].begin(); i != m[word1].end(); ++i)
    	{
    		auto j = m[word2].lower_bound(*i);
    		if(j != m[word2].end())
    			mindis = min(mindis, abs(*j-*i));
    		if(j != m[word2].begin())
    			mindis = min(mindis, abs(*(--j)-*i));
    	}
    	return mindis;
    }
};