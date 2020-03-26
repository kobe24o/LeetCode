class Solution {
	vector<string> ans;
	int n;
public:
    vector<string> permutation(string S) {
    	n = S.size();
    	bool visited[n] = {false};
    	dfs(S,"",0, visited);
		return ans;
    }

    void dfs(string& S, string t, int count, bool* visited)
    {
    	if(count==n)
    	{
    		ans.push_back(t);
    		return;
    	}
    	for(int i = 0; i < n; ++i)
    	{
    		if(!visited[i])
    		{
    			t.push_back(S[i]);
    			visited[i] = true;
    			dfs(S,t,count+1,visited);
    			t.pop_back();
    			visited[i] = false;
    		}
    	}
    }
};