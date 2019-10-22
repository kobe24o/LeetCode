class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1)
        	return false;
        int k = 0b10101010101010101010101010101010;
        if((n&(n-1)) != 0)
        	return false;
        if((n&k) == 0)
        	return true;
        return false;
    }
};