class Solution {
public:
    int countSubstrings(string s, string t) {
    	int ans = 0, diff;
    	for(int i = 0; i < s.size(); ++i)
    	{
    		for(int j = 0; j < t.size(); ++j)
    		{
    			diff = 0;
    			for(int k = 0; i+k < s.size() && j+k < t.size(); ++k)
    			{
    				if(s[i+k] != t[j+k])
    					diff++;
    				if(diff == 1)
    					ans++;
    				else if(diff > 1)
    					break;
    			}
    		}
    	}
    	return ans;
    }
};

class Solution {
public:
    int countSubstrings(string s, string t) {
    	int ans = 0, m = s.size(), n = t.size();
    	vector<vector<int>> same(m, vector<int>(n, 0)),
    						diff(m, vector<int>(n, 0));
    	for(int i = 0; i < m; ++i)
    	{
    		same[i][0] = s[i]==t[0] ? 1 : 0;
    		diff[i][0] = s[i]==t[0] ? 0 : 1;
    	}
    	for(int j = 0; j < n; ++j)
    	{
    		same[0][j] = s[0]==t[j] ? 1 : 0;
    		diff[0][j] = s[0]==t[j] ? 0 : 1;
    	}
    	for(int i = 1; i < m; ++i)
    	{
    		for(int j = 1; j < n; ++j)
    		{
    			if(s[i] == t[j])
    			{
    				same[i][j] = same[i-1][j-1]+1;
    				diff[i][j] = diff[i-1][j-1];
    			}
    			else
    				diff[i][j] = same[i-1][j-1] + 1;
    		}
    	}
    	for(int i = 0; i < m; ++i)
    	{
    		for(int j = 0; j < n; ++j)
    		{
    			ans += diff[i][j];
    		}
    	}
    	return ans;
    }
};