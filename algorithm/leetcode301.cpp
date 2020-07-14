class Solution {
	unordered_set<string> ans;
	int mindel = INT_MAX;
public:
    vector<string> removeInvalidParentheses(string s) {
    	int l = 0, r = 0, del = 0;
    	string t;
    	dfs(s,0,t,l,r,del);
    	return vector<string>(ans.begin(), ans.end());
    }

    void dfs(string& s, int idx, string t, int l, int r, int del)
    {
    	if(del > mindel)
    		return;
    	if(idx == s.size())
    	{
    		if(l==r && del < mindel)
    		{
    			mindel = del;
    			ans.clear();
    			ans.insert(t);
    		}
    		else if(l==r && del == mindel)
    			ans.insert(t);
    		return;
    	}
    	if(s[idx]!='(' && s[idx]!=')')
    		return dfs(s, idx+1, t+s[idx], l, r, del);
    	if(s[idx]=='(') l++;
    	else if(s[idx] == ')') r++;
    	if(l >= r)
    		dfs(s, idx+1, t+s[idx], l, r, del);//不删除
    	if(s[idx]=='(') l--;
    	else if(s[idx] == ')') r--;
    	if(l >= r)
    		dfs(s, idx+1,t, l, r, del+1);//删除
    }
};