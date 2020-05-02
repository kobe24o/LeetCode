class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int N = pow(2,n), i;
        vector<int> ans(N);
        generateGrayCode(ans,n);
        for(i = 0; ans[i]!=start; ++i) ;
        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+N-i);
        reverse(ans.begin()+N-i,ans.end());
        return ans;
    }

    void generateGrayCode(vector<int>& ans, int n)
    {
    	int ni = 1, i, j, k=1;
    	for(i = 0; i < n; ++i)
    	{
    		for(j = ni-1; j >= 0; --j)
    			ans[k++] = ans[j] | (1<<i);
    		ni <<= 1;
    	}
    }
};