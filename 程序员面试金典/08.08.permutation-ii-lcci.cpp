class Solution {
	vector<string> ans;
	int n;	
public:
    vector<string> permutation(string S) {
    	sort(S.begin(), S.end());
    	n = S.size();
    	vector<bool> visited(n,false);
        string str;
    	dfs(S,0,str,visited);
    	return ans;
    }

    void dfs(string& S, int count, string& str, vector<bool>& visited)
	{   
		if(count==n)
		{
			ans.push_back(str);
			return;
		}
	    for(int i = 0; i < n; i++) 
    	{
            if(!visited[i])
            {
                if(i > 0 && S[i-1]==S[i] && !visited[i-1])
                    continue;
                str.push_back(S[i]);
                visited[i] = true;
                dfs(S,count+1,str,visited);
                str.pop_back();
                visited[i] = false;
            }
    	}
	}
};