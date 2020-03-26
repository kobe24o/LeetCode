class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
    	int mask = 0;
    	for(int k = i; k <= j; ++k)
    		mask |= (1<<k);//mask 000001110000
    	N &= (~mask);//清零N中间的位
    	M <<= i;
    	return N | M;
    }
};