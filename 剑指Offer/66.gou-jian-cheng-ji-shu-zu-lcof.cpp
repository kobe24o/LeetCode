class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size(), i, product = 1;
        vector<int> left(n,1), right(n,1);
        for(i = 1; i < n; ++i)
        {
        	product *= a[i-1];
        	left[i] = product;
        }
        product = 1;
        for(i = n-2; i >= 0; i--)
        {
        	product *= a[i+1];
        	right[i] = product;
        }
        vector<int> ans(n);
        for(i = 0; i < n; ++i)
        	ans[i] = left[i]*right[i];
        return ans;
    }
};