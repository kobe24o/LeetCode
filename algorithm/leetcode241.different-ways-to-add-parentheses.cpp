class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	int i, num=0;
    	vector<int> arr;
    	vector<char> op;
    	for(i = 0; i < input.size(); ++i)
    	{
    		if(!isdigit(input[i]))
    		{
    			arr.push_back(num);
    			op.push_back(input[i]);
    			num = 0;
    		}
    		else
    			num = num*10+input[i]-'0';
    	}
    	int n = arr.size(), j, k;
    	vector<vector<vector<int>> dp(n,vector<vector<int>>(n));
    	for(i = 0; i < n; ++i)
    		dp[i][i] = {arr[i]};
    	for(int len = 1; len < n; ++len)
    	{
    		for(i = 0; i < n-len; ++i)
    		{
    			for(int d : dp[i][i+len-1])
    			{
    				if(op[i+len-1]=='+')
    					dp[i][i+len].push_back(d+arr[i+len]);
    				else if(op[i+len-1]=='-')
    					dp[i][i+len].push_back(d-arr[i+len]);
    				else if(op[i+len-1]=='*')
    					dp[i][i+len].push_back(d*arr[i+len]);
    				if(i > 0)
    				{
    					
    				}
    			}
    		}
    	}
    	sort(dp[0][n-1].begin(),dp[0][n-1].end());
    	return dp[0][n-1];
    }
};