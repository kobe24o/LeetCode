class Solution {
public:
    string longestWord(vector<string>& words) {
        if(words.size() < 2)
            return "";
        sort(words.begin(), words.end(),[&](auto a, auto b){
        	if(a.size() == b.size())
        		return a < b;
        	return a.size() > b.size();
        });
        int i, len;
        string ans, sub;
        unordered_set<string> set;
        for(i = 0; i < words.size(); ++i)
        	set.insert(words[i]);
        for(i = 0; i < words.size()-1; ++i)
        {
        	for(len = 1; len < words[i].size(); ++len)
        	{
        		sub = words[i].substr(0,len);
        		if(set.count(sub) && ok(words[i].substr(len), set))
        			return words[i];
        	}
        }
        return "";	
    }

    bool ok(string s, unordered_set<string> &set)
    {
        if(s=="")
            return true;
    	bool good = false;
    	for(int len = 1; len <= s.size(); ++len)
    	{
    		string sub = s.substr(0,len);
    		if(set.count(sub) && ok(s.substr(len),set))
    		{
    			good = true;
    			break;
    		}
    	}
    	return good;
    }
};