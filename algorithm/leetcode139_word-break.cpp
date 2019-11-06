class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i, j, n = s.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        bool dp[n+1] = {false};//dp[j]包含第j个字符为结尾的字符能否拆分
        dp[0] = true;//空字符能拆分
        for(i = 0; i <= n; ++i)
        {
        	if(dp[i] == true)//左半边存在
	        	for(j = i+1; j <= n; ++j)
	        	{
	        		if(set.count(s.substr(i,j-i)))
	        			dp[j] = true;
	        	}
        }
        return dp[n];
    }
};