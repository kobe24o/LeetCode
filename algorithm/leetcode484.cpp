class Solution {
public:
    vector<int> findPermutation(string s) {
    	int n = s.size(), idx, l = 0, r = 0;
    	vector<int> ans(n+1);
    	for(idx = 1; idx <= n+1; ++idx)
    		ans[idx-1] = idx;
    	while(r < n)
    	{
    		if(s[r] == 'I')
    			l++, r++;
    		else//下降
    			r++;
    		if(l < r)
    		{
    			reverse(ans, l, r)
    			l = r = r+1;
    		}
    	}
    	return ans;
    }
    void reverse(vector<int>& ans, int i, int j)
    {
    	while(i < j)
    		swap(s[i++],s[j--]);
    }
};