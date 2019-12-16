class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10)
        	return n;
        long len = 9, i = 2, k = 10, num=9;
        while(len+i*9*pow(10,i-1) < n)
        {
        	len += i*9*pow(10,i-1);
        	num += 9*pow(10,i-1);
        	i++;
        }
        num += (n-len)/i + 1;
        string s.to_string(num);
        return s[(n-len)%i]-'0';
    }
};