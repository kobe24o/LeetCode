class Solution {
public:
    int lastRemaining(int n) {
    	if(n == 1)	return 1;
    	if(n == 2 || n == 3 || n == 4 || n == 5) return 2;
    	if(n == 6 || n == 7) return 4;
    	if(n%4 == 0 || (n-1)%4 == 0) return 6;
    	else 
    		return 8;
    }
};