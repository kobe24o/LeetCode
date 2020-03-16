class Solution {
public:
    int countDigitOne(int n) {
    	int i = 1, count = 0, high, cur, low;
    	while(n/i)//遍历每个位
    	{
    		high = n/(10*i);//高位
    		cur = (n/i)%10;//当前位
    		low = n-(n/i)*i;//低位
    		if(cur == 0)
    			count += high*i;
    		else if(cur == 1)
    			count += high*i+low+1;
    		else
    			count += (high+1)*i;
    		i *= 10;
    	}
    	return count;
    }
};

class Solution {	
public:
    int countDigitOne(int n) {
    	if(n <= 0)
    		return 0;
    	string s = to_string(n);
    	int high = s[0]-'0';
    	int Pow = pow(10, s.size()-1);
    	int last = n - high*Pow;
    	if(high == 1)
    		return countDigitOne(Pow-1)+countDigitOne(last)+last+1;
    		// 最高位是1，如1234, 此时pow = 1000,那么结果由以下三部分构成：
            // (1) dfs(pow - 1)代表[0,999]中1的个数;
            // (2) dfs(last)代表234中1出现的个数;
            // (3) last+1代表固定高位1有多少种情况。
    	else
    		return high*countDigitOne(Pow-1)+countDigitOne(last)+Pow;
    }
};