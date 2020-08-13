class Solution {
	unordered_map<char, string> m;
    unordered_map<string, char> str_char;
	bool match = false;
public:
    bool wordPatternMatch(string pattern, string str) {
        dfs(pattern, str, 0, 0);
        return match;
    }
    void dfs(string& pattern, string& str, int i, int j)
    {
    	if((i < pattern.size() && j >= str.size())
    		|| (i >= pattern.size() && j < str.size()) || match)
    		return;
    	if(i == pattern.size() && j == str.size())
    	{
    		match = true;
    		return;
    	}
    	if(!m.count(pattern[i]))
    	{
    		string val;
    		for(int k = 1; k <= str.size()-j; ++k)
    		{
    			val = str.substr(j, k);
                if(str_char.count(val) && str_char[val] != pattern[i])//"ab"，"aa"
                    continue;
    			m[pattern[i]] = val;
                str_char[val] = pattern[i];
    			dfs(pattern, str, i+1, j+k);
    			m.erase(pattern[i]);
                str_char.erase(val);
    		}
    	}
    	else
    	{
    		string val = m[pattern[i]];
    		int n = val.size();
    		if(str.substr(j, n) != val)
    			return;
    		dfs(pattern, str, i+1, j+n);
    	}
    }
};