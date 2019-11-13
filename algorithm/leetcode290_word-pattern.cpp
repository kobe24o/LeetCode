class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i, j;
        istringstream in(str);
        string word;
        unordered_map<char, string> m;
        unordered_map<string, char> n;
        for(i = 0; i < pattern.length(); ++i)
        {
        	if(!(in >> word))//输出出错
        		return false;
        	if(!m.count(pattern[i]) && !n.count(word))
        	{
        		m[pattern[i]] = word;
        		n[word] = pattern[i];
        	}
        	else//有char在m中，或者word在n中
        	{
        		if(m.count(pattern[i]) && m[pattern[i]] != word)
        			return false;
        		if(n.count(word) && n[word] != pattern[i])
        			return false;
        	}
        }
        if(in >> word)//还能输入,str长了，不匹配
        	return false;
        return true;
    }
};