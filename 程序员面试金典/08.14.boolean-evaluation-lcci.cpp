class Solution {
	int sum = 0;
	int n;
public:
    int countEval(string s, int result) {
    	n = s.size()/2; //运算次数
    	dfs(s,0,result);
    	return sum;
    }

    void dfs(string& s, int count, int result)
    {
    	if(count==n)
    	{
    		if(s[0]-'0' == result)
    			sum++;
    		return;
    	}
    	string origin, b;
    	for(int i = 0; i < s.size()/2; ++i)
    	{
    		origin = s.substr(2*i,3);
    		b = operation(origin);
    		s.replace(2*i,3,b);
    		dfs(s,count+1,result);
    		s.replace(2*i,1,origin);
    	}
    }

    string operation(string str)
    {
    	int a = str[0]-'0', b = str[2]-'0';
    	int ans;
    	if(str[1] == '&')
    		ans = a&b;
    	else if(str[1] == '|')
    		ans = a|b;
    	else
    		ans = a^b;
    	return ans==1 ? "1" : "0";
    }
};