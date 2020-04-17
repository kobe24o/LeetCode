class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    	int i, j=0, l, r;
    	for(i = 1; i < arr.size(); ++i)
    		arr[i] ^= arr[i-1];
    	vector<int> ans(queries.size());
    	for(i = 0; i < queries.size(); ++i)
    	{
    		l = queries[i][0];
    		r = queries[i][1];
    		ans[j++] = (l > 0 ? arr[r]^arr[l-1] : arr[r]);
    	}
    	return ans;
    }
};