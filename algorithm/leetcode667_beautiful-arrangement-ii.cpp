class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i;
        vector<int> ans(n);
        for(i = 0; i < n; ++i)
        	ans[i] = i+1;
        for(i = 1; i < k; ++i)
        	reverse(ans,i,n-1);
        return ans;
    }

    void reverse(vector<int>& arr, int i, int j)
    {
    	while(i < j)
    		swap(arr[i++], arr[j--]);
    }
};