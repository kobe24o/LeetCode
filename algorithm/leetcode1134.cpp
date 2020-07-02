class Solution {
public:
    bool isArmstrong(int N) {
        int bits = 0, sum = 0, n = N;
        while(n)
        {
        	bits++;
        	n /= 10;
        }
        n = N;
        while(n)
        {
        	sum += pow(n%10, bits);
        	n /= 10;
        }
        return sum==N;
    }
};