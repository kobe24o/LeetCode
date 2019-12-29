class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size(), i;
        vector<int> s(n);
        sort(arr.begin(), arr.end());
        s[0] = arr[0];
        for(i = 1; i < n; ++i)
        {
        	s[i] = s[i-1] + arr[i];
        }
        if(target >= s[n-1])
        	return arr[n-1];
        if(target <= n*arr[0])
        {
        	if(abs(target/n*n -target) <= abs((target/n+1)*n - target))
        		return target/n;
        	else
        		return target/n+1;
        }
        int l = 0, r = n-1, mid, p, q;
        while(l <= r)
        {
        	mid = l+((r-l)>>1);
        	p = s[mid]+(n-1-mid)*arr[mid];
        	q = mid+1 == n ? s[n-1] : s[mid+1]+(n-1-mid-1)*arr[mid+1];
        	if(target-p >= 0 && target-q <= 0)
        		break;
        	else if(target-p <= 0 && target-q <= 0)
        		r = mid-1;
        	else if(target-p >= 0 && target-q >= 0)
        		l = mid+1;
        }
        if(mid == n-1)
        	return arr[n-1];
        int k = (target-s[mid])
        p = s[mid]+(n-1-mid)*arr[mid];
        q = s[mid+1]+(n-1-mid-1)*arr[mid+1];
        if(abs(target-p) <= abs(target-q))
        	return arr[mid];
        return arr[mid+1];
    }
};