class Solution {
public:
    int superPow(int a, vector<int>& b) {
    	int ans = 1, i;
    	for(i = 0; i < b.size(); ++i)
    		ans = (qpow(ans,10,1337)%1337)*(qpow(a, b[i], 1337)%1337);
    	return ans%1337;
    }
    int qpow(int x, int p, int c)
    {
    	int ans = 1;
    	while(p)
    	{
    		if((p&1)==1)
    			ans = (ans%c)*(x%c);
    		x = (x%c)*(x%c);
    		p >>= 1;
    	}
    	return ans%c;
    }
};