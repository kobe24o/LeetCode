class Solution {
	vector<vector<string>> combination;
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
    	unordered_set<string> s;
    	for(auto& sy : synonyms)
    		for(auto& str : sy)
    			s.insert(str);
    	vector<string> sentenceWords;
    	string w;
    	for(int i = 0; i < text.size(); ++i)
    	{
    		if(s[i] == ' ' || i = text.size()-1)
    		{
    			sentenceWords.push_back(w);
    			w = "";
    		}
    		else
    			w += s[i];
    	}
    	vector<string> path;
    	bt(synonyms, 0, path);
    	vector<string> ans;
    	for(auto& combin : combination)
    	{
    		w = "";
    		for(int i = 0, j = 0; i < sentenceWords.size(); ++i)
    		{
    			if(s.count(sentenceWords[i]))
    				w += combin[j++] + " ";
    			else
    				w += sentenceWords[i] + " ";
    		}
    		w.pop_back();
    		ans.push_back(w);
    	}
    	return ans;
    }

    void bt(vector<vector<string>>& synonyms, int i, vector<string>& path)
    {
    	if(i == synonyms.size())
    	{
    		combination.push_back(path);
    		return;
    	}
    	for(int j = 0; j < synonyms[i].size(); ++j)
    	{
    		path.push_back(synonyms[i][j]);
    		bt(synonyms,i+1,path);
    		path.pop_back();
    	}
    }
};