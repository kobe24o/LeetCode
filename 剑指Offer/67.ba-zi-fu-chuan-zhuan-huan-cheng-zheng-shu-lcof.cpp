class Solution {
public:
    int strToInt(string s) {
    	int i, n = s.size();
		while(i < n && s[i] == ' ')
			i++;
		if(!isdigit(s[i]) && s[i] != '+' && s[i] != '-')
			return 0;
		long num = 0;
		bool negative = false;
		if(s[i] == '+')
			i++;
		else if(s[i] == '-')
		{
			negative = true;
			i++;
		}
		while(i < n && isdigit(s[i]))
		{
			num = num*10 + (negative ? -(s[i]-'0') : (s[i]-'0'));
			if(num >= INT_MAX)
				return INT_MAX;
			else if(num <= INT_MIN)
				return INT_MIN;
		}
		return num;
    }
};