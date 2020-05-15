class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	if(s.size() < p.size())
    		return {};
    	int pcount[26] = {0}, scount[26] = {0}, i, np = p.size();
    	for(i = 0; i < np; ++i)
    	{
    		pcount[p[i]-'a']++;
    		scount[s[i]-'a']++;
    	}
    	vector<int> ans;
    	if(eq(pcount, scount))
    		ans.push_back(0);
    	for(i = np; i < s.size(); ++i)
    	{
    		scount[s[i]-'a']++;
    		scount[s[i-np]-'a']--;
    		if(eq(pcount, scount))
    			ans.push_back(i-np+1);
    	}
    	return ans;
    }
    bool eq(int *pc, int *sc)
    {
    	for(int i = 0; i < 26; ++i)
    		if(pc[i] != sc[i])
    			return false;
		return true;
    }
};