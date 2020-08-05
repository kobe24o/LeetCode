class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
    	string rev, all;
    	for(string& s : strs)
    	{
    		rev = s;
    		reverse(rev.begin(), rev.end());
    		if(rev > s)
    			s = rev;
    	}
    	string ans, temp;
    	for(int i = 0, j, k; i < strs.size(); ++i)
    	{
            temp = "";
    		for(j = i+1; j < strs.size(); ++j)
    			temp += strs[j];
    		for(j = 0; j < i; ++j)
    			temp += strs[j];
    		for(j = 0; j <= strs[i].size(); ++j)
    		{
    			rev = strs[i].substr(j)+temp+strs[i].substr(0,j);
    			ans = max(ans, rev);
    		}
            reverse(strs[i].begin(), strs[i].end());
    		for(j = 0; j <= strs[i].size(); ++j)
    		{
    			rev = strs[i].substr(j)+temp+strs[i].substr(0,j);
    			ans = max(ans, rev);
    		}
            reverse(strs[i].begin(), strs[i].end());
    	}
    	return ans;
    }
};