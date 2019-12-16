// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
	int a, b;
public:
    int rand10() {
        a = rand7();
        b = rand7();
        while(a == 7)
        	a = rand7(); //a = 1--6均匀分布
        while(b > 5)
        	b = rand7(); //b = 1--5均匀分布
        if(a%2)	//a有50%的概率是奇数(1,3,5)
        	return b;//1--5
        return 5+b;//6--10(a有50%概率是偶数)
    }
};

class Solution {
	int a, b, n;
public:
    int rand10() {
    	do
    	{
	        a = rand7();
	        b = rand7();
	        n = (a-1)*7+b;
	    }while(n > 40);
	    return (n-1)%10 + 1;
    }
};