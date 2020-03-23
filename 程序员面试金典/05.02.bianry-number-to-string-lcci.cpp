class Solution {
public:
    string printBin(double num) {
    	if(num < 0 || num > 1.0)
    		return "ERROR";
    	string ans = "0.";
    	int bits = 2;
    	while(num > 0)
    	{
    		num *= 2;//*2 进制数
    		if(num >= 1.0)
    		{
    			ans += '1';
    			num -= 1;
    		}
    		else
    			ans += '0';
    		bits++;
    		if(bits > 32)
    			return "ERROR";
    	}
    	return ans;
    }
};