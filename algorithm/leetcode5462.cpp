class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
    	int n = s.size(), i, j, k, len = 1, codelen = 1;
    	char prev = s[0];
    	string size;
    	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2,INT_MAX)));
    	dp[0][0][0] = 0;
    	dp[1][0][0] = 1;
    	for(i = 1; i < n; ++i)
    	{
    		if(s[i] == prev)
    			len++;
    		size = (len > 1 ? )
    	}
    }
};