class Solution {
public:
    int myAtoi(string str) {
    	bool getstr = false, positive = false, negative = false;
    	double num = 0;
        for(int i = 0; i < str.size(); ++i)
        {
        	if(str[i] == ' ' && !getstr)
        		continue;
        	else if(str[i] == ' ' && getstr)
        		break;
        	if(positive && negative)
        		return 0;
        	if(str[i] >= '0' && str[i] <= '9')
        	{
        		getstr = true;
        		num *= 10;
        		num += (str[i]-'0');
        	}
        	else if(str[i] == '-')
        	{
        		getstr = true;
        		negative = true;
        	}
        	else if(str[i] == '+')
        	{
        		getstr = true;
        		positive = true;
        	}
        	else if(str[i] == '.')
        		break;
        	else
        	{
        		if(!getstr)
        			return 0;
    			else
        			break;	
			}
        }
        if(!negative)
    	{
    		if(num <= INT_MAX)
    			return num;
    		return	INT_MAX;
    	}
    	else
    	{
    		if(num >= INT_MIN)
    			return -num;
    		return	INT_MIN;
    	}
    }
};

class Solution {
public:
    int myAtoi(string str) {
    	int d=0;
        istringstream is(str);
        is >> d;
        return d;
    }
};