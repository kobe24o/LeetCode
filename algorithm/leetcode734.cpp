class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
    	if(words1.size() != words2.size())
    		return false;
    	unordered_map<string,unordered_set<string>> m;
    	for(auto& p : pairs)
    	{
    		m[p[0]].insert(p[1]);
    		m[p[1]].insert(p[0]);
    	}
    	for(int i = 0; i < words1.size(); ++i)
    	{
            if(words1[i] == words2[i])
                continue;
    		if(m[words1[i]].find(words2[i])==m[words1[i]].end()
    			&& m[words2[i]].find(words1[i])==m[words2[i]].end())
    			return false;
    	}
    	return true;
    }
};