class Solution {
	vector<string> ans;
public:
    vector<string> expand(string S) {
    	vector<vector<char>> str;
    	vector<char> t;
        int count = 0;
    	for(int i = 0; i < S.size(); ++i)
    	{
    		if(isalpha(S[i]))
    			t.push_back(S[i]);
    		else if(S[i] == '}' || (S[i] == '{' && !t.empty()))
    		{
                if(S[i] == '}') count++;
    			sort(t.begin(), t.end());
    			str.push_back(t);
    			t.clear();
    		}
    	}
        if(!t.empty())
        {
            sort(t.begin(), t.end());
    		str.push_back(t);
        }
        if(count == 0) return {S};
    	dfs(str, "", 0);
    	return ans;
    }

    void dfs(vector<vector<char>>& str, string s, int i)
    {
    	if(i == str.size())
    	{
    		ans.push_back(s);
    		return;
    	}
    	for(int j = 0; j < str[i].size(); ++j)
    		dfs(str, s+str[i][j], i+1);
    }
};