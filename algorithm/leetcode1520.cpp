class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
    	vector<int> start(26,-1), end(26,-1);
    	int i = 0, n = s.size(), l, r, last = -1;
    	for(i = 0; i < n; ++i)
    	{
    		char ch = s[i];
    		if(start[ch-'a'] == -1)
    			start[ch-'a'] = i;
    		end[ch-'a'] = i;
    	}
    	vector<int> endpos;
    	for(auto e : end)
    		if(e != -1)
    			endpos.push_back(e);
    	sort(endpos.begin(), endpos.end());
    	vector<string> ans;
    	for(auto e : endpos)
    	{
    		l = start[s[e]-'a'];
    		r = e;
    		while(l < r)
    		{
    			if(end[s[r]-'a'] > e || l <= last)
    				break;
    			l = min(l, start[s[r]-'a']);
    			r--;
    		}
    		if(r == l)
    		{
                ans.push_back(s.substr(l, e-l+1));
                last = e;
            }
    	}
    	return ans;
    }
};