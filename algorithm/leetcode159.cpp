class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
    	int k = 2, i = 0, j = 0, maxlen = 0;
    	unordered_map<char, int> m;
    	while(j < s.size())
    	{
    		if(m.size() <= k)
    		{
                ++m[s[j++]];
    		}

            while(m.size()>2)
            {
                if(--m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
    		maxlen = max(maxlen, j-i);
    	}
    	return maxlen;
    }
};