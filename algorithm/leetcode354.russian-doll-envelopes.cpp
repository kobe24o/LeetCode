class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),[&](auto a, auto b){
        	if(a[1]==b[1])
        		return a[0] > b[0];//相等情况下，另一分量逆序
        	return a[1] < b[1];//【1】分量有序了
        });
        int i, idx=0, n = envelopes.size();
        vector<int> dp(n);
        for(i = 0; i < n; ++i)
        {
        	auto it = lower_bound(dp.begin(),dp.begin()+idx,envelopes[i][0]);
        	*it = envelopes[i][0];
        	if(it-dp.begin() == idx)
        		idx++;
        }
        return idx;
    }
};