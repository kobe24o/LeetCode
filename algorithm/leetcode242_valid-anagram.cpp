class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0}, i;
        for(int i = 0; i < s.size(); ++i)
        {
        	count[s[i]-'a']++;
        }
        for(i = 0; i < t.size(); ++i)
        {
        	if(--count[t[i]-'a'] < 0)
        		return false;
        }
        for(i = 0; i < 26; ++i)
        {
        	if(count[i] != 0)
        		return false;
        }
        return true;
    }
};