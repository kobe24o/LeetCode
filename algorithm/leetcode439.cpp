class Solution {
public:
    string parseTernary(string expression) {
    	int c1 = 0, c2 = 0, n = expression.size();
    	for(int i = 1; i < n; ++i)
    	{
    		if(expression[i]=='?')
    			c1++;
    		else if(expression[i]==':')
    			c2++;
    		if(c1 == c2)
    		{
    			return expression[0]=='T' ? parseTernary(expression.substr(2, i-2)) : parseTernary(expression.substr(i+1));
    		}
    	}
    	return expression;
    }
};


class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s1;
        for(int i = expression.length() - 1; i >= 2; i -= 2)//找?或者:
        {
            if(expression[i-1] == ':')//当前是 :
                s1.push(expression[i]);
            else//当前是?
            {
                expression[i-2] = expression[i-2] == 'T' ? expression[i] : s1.top();
                // ? 前面 更新为表达式的值
                s1.pop();
            }
        }
        return string(1,expression[0]);
    }
};