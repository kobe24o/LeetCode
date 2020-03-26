class Solution {
	vector<string> ans;
	int N;
	vector<char> ch ={'(',')'};
public:
    vector<string> generateParenthesis(int n) {
    	N = 2*n;
    	string t;
    	dfs(t,0,0,n,0);
    	return ans;
    }

    void dfs(string& t, int l, int r, int n, int count)
    {
    	if(l<r || l > n || r > n)
    		return;
    	if(count == N)
    	{
    		ans.push_back(t);
    		return;
    	}
    	for(int i = 0; i < 2; ++i)
    	{
    		t.push_back(ch[i]);
    		if(i==0) dfs(t,l+1,r,n,count+1);
    		else     dfs(t,l,r+1,n,count+1);
    		t.pop_back();
    	}
    }
};