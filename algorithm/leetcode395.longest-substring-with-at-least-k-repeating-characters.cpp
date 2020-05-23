class Solution {
	int maxlen = 0;
public:
    int longestSubstring(string s, int k) {
        if(s.size() <= maxlen)
            return 0;
    	int count[26] = {0}, i, left = 0, right;
    	for(i = 0; i < s.size(); ++i)
    		count[s[i]-'a']++;
    	vector<int> split;
    	for(i = 0; i < s.size(); ++i)
    	{
    		if(count[s[i]-'a'] > 0 && count[s[i]-'a'] < k)
    			split.push_back(i);
    	}
    	if(split.empty())
    		maxlen = max(maxlen, int(s.size()));
        for(i = 0; i < split.size(); ++i)
        {
            longestSubstring(s.substr(left, split[i]-left), k);
            left = split[i]+1;
            if(i == split.size()-1 && left < s.size())
                longestSubstring(s.substr(left, s.size()-left), k);
        }
        return maxlen;
    }
};