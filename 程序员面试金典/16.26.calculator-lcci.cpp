class Solution {
public:
    int calculate(string s) {
    	long a, sum, i = 0;
    	char op = '+';
        while(i < s.size() && s[i]==' ')
            i++;//处理空格
    	stack<int> stk;
    	if(i < s.size() && s[i] == '+')
    		i++;
    	else if(i < s.size() && s[i] == '-')
    	{
    		op = '-';
    		i++;
    	}
    	for( ; i < s.size(); ++i)
    	{
    		a = 0;
            while(i < s.size() && s[i]==' ')
                i++;//处理空格
    		while(i < s.size() && isdigit(s[i]))
    			a = a*10+s[i++]-'0';
			if(op == '*')
    		{	
    			a = stk.top() * a;
    			stk.pop();
    			sum = 0;
    			while(!stk.empty())
    			{
    				sum += stk.top();
    				stk.pop();
    			}
    			stk.push(sum);
    			stk.push(a);
    		}
    		else if(op == '/')
    		{	
    			a = stk.top() / a;
    			stk.pop();
    			sum = 0;
    			while(!stk.empty())
    			{
    				sum += stk.top();
    				stk.pop();
    			}
    			stk.push(sum);
    			stk.push(a);
    		}
    		else if(op == '-')
    			stk.push(-a);
    		else
    			stk.push(a);
            while(i < s.size() && s[i]==' ')
                i++;//处理空格
    		if(i < s.size())
    			op = s[i];
    	}
    	sum = 0;
    	while(!stk.empty())
    	{
    		sum += stk.top();
    		stk.pop();
    	}
    	return sum;
    }
};