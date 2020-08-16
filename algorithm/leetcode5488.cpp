class Solution {
public:
    int minOperations(int n) {
    	int an_1 = 2*(n-1)+1;
    	int mid = (an_1+1)/2;
    	if(n&1)
    		return n/2*mid-(1+mid-2)/2*(n/2);
        return n/2*mid-(1+mid-1)/2*(n/2);
    }
};