class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int t, i;
        for(t = 1; t <= s.size()/2; ++t)
        {
        	if(s.size()%t)
        		continue;//不能整除肯定不是
        	i = 0;
        	while(i < s.size()-t && s[i] == s[i+t])
        		i++;
        	if(i == s.size()-t)
        		return true;
        }
        return false;
    }
};