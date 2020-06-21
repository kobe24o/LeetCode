class Solution {
public:
    int xorOperation(int n, int start) {
    	int i, XOR = 0;
    	for(i = 0; i < n; i++)
    	{
    		XOR ^= (star+2*i);
    	}
    	return XOR;
    }
};