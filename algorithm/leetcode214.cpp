class Solution {
public:
    string shortestPalindrome(string s) {
    	long long n = s.size(), i, idx = -1, base = 1, mod = 1e9+7;
    	long long left = 0, right = 0;
    	for(i = 0; i < n; i++) 
    	{
    		left = (left*131 + s[i])%mod;
    		right = (right + s[i]*base)%mod;
    		if(left == right)
    			idx = i;
    		base *= 131;
            base %= mod;
    	}
    	string A = s.substr(idx+1);
    	reverse(A.begin(), A.end());
    	return A+s;
    }
};