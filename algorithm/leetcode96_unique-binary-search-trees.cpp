class Solution {
public:
    int numTrees(int n) {
        int g[n+1] = {0}, i, j;
        g[0] = 1;
        g[1] = 1;
        for(i = 2; i <= n; ++i)
        	for(j = 0; j < i; ++j)
        		g[i] += g[j]*g[i-j-1];
    	return g[n];
    }
};