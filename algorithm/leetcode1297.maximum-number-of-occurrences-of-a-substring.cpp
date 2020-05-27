class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    	unordered_map<string, int> m;
    	int i, j, c, count, maxcount = 0, n = s.size();
    	string t;
    	for(i = 0; i <= n-minSize; ++i)
    	{
    		t = s.substr(i, minSize);
    		count = 0, c = 0;
    		for(j = 0; j < t.size(); ++j)
    		{
    			if(((count>>(t[j]-'a'))&1)==0)
    			{
    				c++;
    				count |= (1<<(t[j]-'a'));
    			}
    		}
    		if(c <= maxLetters)
    		{
    			m[t]++;
    			maxcount = max(maxcount,m[t]);
    		}
    	}
    	return maxcount;
    }
};