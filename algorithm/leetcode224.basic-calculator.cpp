class Solution {
public:
    int calculate(string s) {
    	stack<int> stk;
    	int sign = 1;
        long num = 0, sum = 0;
    	for(int i = 0; i < s.size(); ++i)
    	{
    		if(s[i] =='(')
    		{	//遇见左括号，把括号外面的结果入栈，外面的符号入栈
                stk.push(sum);
    			stk.push(sign);
                sign = 1;//下次的符号初始值
                sum = 0;
                num = 0;
    		}
    		else if(s[i] =='+')
    		{
    			sum += sign*num;//和
    			sign = 1;//当前符号
    			num = 0;
    		}
    		else if(s[i] =='-')
    		{
    			sum += sign*num;
    			sign = -1;
    			num = 0;
    		}
    		else if(s[i] ==')')
    		{	//遇到右括号
    			sum += sign*num;//括号内的和加起来
    			sign = stk.top();//括号外的符号
    			stk.pop();//符号出栈
                sum = sign*sum + stk.top();//和*符号+外面的和
                stk.pop();//外面的和出栈
    			num = 0;
    		}
    		else if(isdigit(s[i]))
    			num = num*10+s[i]-'0';
    	}
    	return sum+sign*num;
    }
};