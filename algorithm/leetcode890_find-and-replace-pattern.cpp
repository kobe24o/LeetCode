class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,int> m;//pattern字符，pattern与word的字符差
        unordered_map<char,int> n;//word字符，pattern与word的字符差
        vector<string> ans;
        int i;
        bool good;
        for(string &word : words)
        {
        	if(word.size() != pattern.size())
        		continue;
        	m.clear();
        	n.clear();
        	good = true;
        	for(i = 0; i < pattern.size(); ++i)
        	{
        		if(m.find(pattern[i]) == m.end())
        			m[pattern[i]] = word[i]-pattern[i];
        		else
        		{
        			if(m[pattern[i]] != word[i]-pattern[i])
        			{
        				good = false;
        				break;
        			}
        		}

        		if(n.find(word[i]) == n.end())
        			n[word[i]] = word[i]-pattern[i];
        		else
        		{
        			if(n[word[i]] != word[i]-pattern[i])
        			{
        				good = false;
        				break;
        			}
        		}
        	}
        	if(good)
        		ans.push_back(word);
        }
        return ans;
    }
};