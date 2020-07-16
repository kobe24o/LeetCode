class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
    	unordered_map<char,int> m;
    	int maxlen = 0;
    	for(int i = 0, j = 0; i < s.size(); ++i)
    	{
    		if(m.size() <= k)
    			m[s[i]]++;
    		while(m.size()>k)
    		{
    			if(--m[s[j]] == 0)
    				m.erase(s[j]);
    			j++;
    		}
    		maxlen = max(maxlen, i-j+1);
    	}
    	return maxlen;
    }
};