class Solution {
public:
    int translateNum(int num) {
    	string str = to_string(num);
    	int i, n = str.size();
    	int dp[n+1] = {0};
    	dp[0] = 1;//第0个字符空串
    	dp[1] = 1;//第一个字符翻译，只有1种可能
    	for(i = 2; i <= n; ++i)
    	{
    		if(str[i-2]=='1' ||(str[i-2]=='2' && str[i-1] <='5'))
    			//该种情况，可以把这两位数，翻成2个或者1个字符
    			dp[i] = dp[i-2]+dp[i-1];
    		else//34,29，只能单独翻译
    			dp[i] = dp[i-1];
    	}
    	return dp[n];
    }
};