class Solution {
public:
    string fractionAddition(string expression) {
    	bool positive = true, founddown = false;
    	int up = 0, down = 0, a = 0, b = 0;
    	for(int i = 0; i < expression.size(); ++i)
    	{
    		if(expression[i] == '+')
    		{
    			positive = true;
    			founddown = false;//找到分母
    			add(up,down,a,b,positive);
    			a=b=0;
    		}
    		else if(expression[i] == '-')
    		{
    			positive = false;
    			founddown = false;
    			add(up,down,a,b,positive);
    			a=b=0;
    		}
    		else if(expression[i] == '/')
    			founddown = true;
    		else
    		{
    			if(founddown)
    				b = b*10+expression[i]-'0';
    			else
    				a = a*10+expression[i]-'0';
    		}
    	}
    	add(up,down,a,b,positive);
    	return to_string(up)+"/"+to_string(down);
    }

    void add(int &up, int &down, int a, int b, bool positive)
    {
    	if(down == 0 && b == 0)
    		return;
    	if(down == 0 && b != 0)
    	{
    		up = positive?a:-a, down = b;
    		return;
    	}
    	int t_up = 0, t_down = down*b;
    	t_up += up*b + (positive?a:-a)*down;
    	int g = gcd(t_up, t_down);
    	up = t_up/g;
    	down = t_down/g;
    }

    int gcd(int a, int b)
    {
    	int r;
    	while(b)
    	{
    		r = a%b;
    		a = b;
    		b = r;
    	}
    	return a;
    }
};