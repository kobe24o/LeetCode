class Solution {
public:
    int numSplits(string s) {
    	unordered_map<char,int> l, r;
    	int i, ans = 0;
    	l[s[0]] = 1;
    	for(i = 1; i < s.size(); ++i)
    		r[s[i]]++;
    	for(i = 1; i < s.size(); ++i)
    	{
    		if(l.size() == r.size())
    			ans++;
    		l[s[i]]++;
    		if(--r[s[i]] == 0)
    			r.erase(s[i]);
    	}
    	return ans;
    }
};