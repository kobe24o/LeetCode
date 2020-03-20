class Solution {
public:
    int convertInteger(int A, int B) {
        int s = A^B;
    	int count = 0;
    	for(int i = 0; i < 32; ++i)
    	{
    		if((s>>i)&1)
    			count++;
    	}
    	return count;
    }
};