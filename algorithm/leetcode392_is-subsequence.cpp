class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size())
        	return false;
        int i = 0, j = 0;
        for( ; j < t.size(); ++j)
        {
        	if(s[i] == t[j])
        		i++;
        }
        return (i==s.size());
    }
};