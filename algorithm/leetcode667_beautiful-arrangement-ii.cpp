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

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i, d = n-1;
        bool flag = true;
        vector<int> ans(n,1);
        for(i = 1; i < k; ++i,--d)
        {
        	if(flag)
        		ans[i] = ans[i-1]+d;
        	else
        		ans[i] = ans[i-1]-d;
        	flag = !flag;
        }
        d = 1;
        for( ; i < n; ++i)
        {
        	if(flag)
        		ans[i] = ans[i-1]+d;
        	else
        		ans[i] = ans[i-1]-d;
        }
        return ans;
    }
};