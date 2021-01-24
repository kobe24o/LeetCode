class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
    	int n = encoded.size();
    	vector<int> ans(n+1);
    	vector<int> preEnc(encoded);
    	for(int i = 1; i < encoded.size(); ++i)
    		preEnc[i] ^= preEnc[i-1];
    	int a2_an = 0;
    	for(int i = 0; i < preEnc.size(); ++i)
    		a2_an ^= preEnc[i];
    	int all = 0;
        for(int i = 1; i <= n+1; ++i)
            all ^= i;
    	ans[0] = all^a2_an;
    	for(int i = 1; i <= n; ++i)
    		ans[i] = ans[i-1]^encoded[i-1];
    	return ans;
    }
};