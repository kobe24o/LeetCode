class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	int i, j, k, num=0;
    	vector<int> arr;//数字存起来
    	vector<char> op;//操作符存起来
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
        arr.push_back(num);//最后一个数字
    	int n = arr.size();
    	vector<vector<vector<int>>> dp(n,vector<vector<int>>(n));
    	for(i = 0; i < n-1; ++i)
        {
            dp[i][i] = {arr[i]};//初始化dp[i][i]
            if(op[i]=='+')
    		    dp[i][i+1] = {arr[i]+arr[i+1]};//初始化dp[i][i+1]
            else if(op[i]=='-')
                dp[i][i+1] = {arr[i]-arr[i+1]};
            else if(op[i]=='*')
                dp[i][i+1] = {arr[i]*arr[i+1]};
        }
        dp[n-1][n-1] = {arr[n-1]};//初始化dp[i][i]
    	for(int len = 2; len < n; ++len)
    	{	//按长度dp
    		for(i = 0; i < n-len; ++i)
    		{	//左端点
                for(j = i; j < i+len; ++j)
                {	//中间端点
                    for(int dl : dp[i][j])
                    {	//左边的数值
                        for(int dr : dp[j+1][i+len])//左边的数值
                            if(op[j]=='+')
                                dp[i][i+len].push_back(dl+dr);
                            else if(op[j]=='-')
                                dp[i][i+len].push_back(dl-dr);
                            else if(op[j]=='*')
                                dp[i][i+len].push_back(dl*dr);
                    }
                }
    		}
    	}
    	sort(dp[0][n-1].begin(),dp[0][n-1].end());
    	return dp[0][n-1];
    }
};