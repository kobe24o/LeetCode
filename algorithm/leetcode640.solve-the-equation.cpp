class Solution {
public:
    string solveEquation(string equation) {
    	int i, lnum = 0, rnum = 0, lcoe = 0, rcoe = 0, n=0;
    	char ch;
    	bool positive = true;
    	for(i = 0; equation[i] != '='; ++i)
    	{
    		ch = equation[i];
    		if(ch == 'x')
    		{

    			lcoe += n==0 ? ((i>0&&equation[i-1]=='0')? 0 : (positive ? 1 : -1)) : (positive ? n : -n);
    			n=0;
    		}
    		else if(ch == '-')
    		{
    			lnum += (positive ? n : -n);
    			positive = false;
    			n=0;
    		}
    		else if(ch == '+')
    		{
    			lnum += (positive ? n : -n);
    			positive = true;
    			n=0;
    		}
    		else
    		{
    			n = 10*n+ch-'0';
    		}
    	}
    	if(equation[i-1] != 'x')
    		lnum += (positive ? n : -n);
        positive = true;
        n = 0;
    	for(i++; i < equation.size(); ++i)
    	{
    		ch = equation[i];
    		if(ch == 'x')
    		{
    			rcoe += n==0 ? ((equation[i-1]=='0')? 0 : (positive ? 1 : -1)) : (positive ? n : -n);
    			n=0;
    		}
    		else if(ch == '-')
    		{
    			rnum += (positive ? n : -n);
    			positive = false;
    			n=0;
    		}
    		else if(ch == '+')
    		{
    			rnum += (positive ? n : -n);
    			positive = true;
    			n=0;
    		}
    		else
    		{
    			n = 10*n+ch-'0';
    		}
    	}
    	if(equation[i-1] != 'x')
    		rnum += (positive ? n : -n);

    	if(lcoe == rcoe && lnum == rnum)
    		return "Infinite solutions";
    	if(lcoe == rcoe && lnum != rnum)
    		return "No solution";
    	int ans = (lnum-rnum)/(rcoe-lcoe);
    	return "x="+to_string(ans);
    }
};