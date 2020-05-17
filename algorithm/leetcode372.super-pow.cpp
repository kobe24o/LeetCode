class Solution {
public:
    int superPow(int a, vector<int>& b) {
    	int ans = 1, i, p = 1;
    	for(i = 0; i < b.size(); ++i,p*=10)
    	{
    		ans *= pow(a%1337,b[i])%1337;
    	}
    	return ans;
    }
};