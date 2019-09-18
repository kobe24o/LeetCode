class Solution {
public:
    int addDigits(int num) {
        int sum;
        while(num >= 10)
        {
        	sum = 0;
        	while(num)
        	{
        		sum += num % 10;
        		num /= 10;
        	}
        	num = sum;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        if(num != 0 && num%9 == 0)
        	return 9;
        return num%9;
    }
};