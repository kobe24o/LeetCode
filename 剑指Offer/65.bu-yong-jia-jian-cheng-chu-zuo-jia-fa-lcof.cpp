class Solution {
public:
    int add(int a, int b) {
    	int sum;
        while(b)
        {
        	sum = a^b;//不带进位的加法
        	b = (unsigned int)(a&b)<<1;//b是进位
        	a = sum;//a是和，当b进位为0时，结束
        }
        return a;
    }
};

class Solution {
public:
    int add(int a, int b) {
        if(b == 0)
        	return a;
        return add(a^b, (unsigned int)(a&b)<<1);
    }
};