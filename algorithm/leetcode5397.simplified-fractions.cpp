class Solution {
public:
    vector<string> simplifiedFractions(int n) {
    	unordered_set<string> ans;
    	int i, k, g, u, d;
    	for(k = 2; k <= n; ++k)
	    	for(i = 1; i < k; ++i)
	    	{
	    		g = __gcd(i,k);
	    		u = i/g;
	    		d = k/g;
	    		ans.insert(to_string(u)+"/"+to_string(d));
	    	}
    	return vector<string>(ans.begin(),ans.end());
    }
};