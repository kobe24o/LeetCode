class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
    	int i, len, maxlen = 0;
    	unordered_set<string> s;
    	for(i = 0; i < words.size(); ++i)
    	{
    		s.insert(words[i]);
    		maxlen = max(maxlen, (int)words[i].size());
    	}
    	vector<vector<int>> ans;
    	for(i = 0; i < text.size(); ++i)
    	{
    		for(len = 1; len <= maxlen; ++len)
    		{
    			if(i+len-1 < text.size() && s.find(text.substr(i,len))!=s.end())
    				ans.push_back({i,i+len-1});
    		}
    	}
    	return ans;
    }
};