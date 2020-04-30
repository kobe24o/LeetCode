class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
    	int i, l, r, mid, idx, diff, mindiff = INT_MAX, n = arr.size(), ans=INT_MAX;
    	sort(arr.begin(),arr.end());
    	vector<int> presum(arr);
    	for(i = 1; i < n; ++i)
    		presum[i] += presum[i-1];
    	l = 0, r = arr[n-1];
    	while(l <= r)
    	{
    		mid = l+((r-l)>>1);
    		idx = binsearch(arr, mid);
    		diff = (idx>0? presum[idx-1] : 0) +(n-idx)*mid-target;
    		if(abs(diff) < mindiff)
    		{
    			mindiff = abs(diff);
    			ans = mid;
    		}
            else if((abs(diff) == mindiff))
                ans = min(ans,mid);
    		if(diff < 0)
    			l = mid+1;
    		else if(diff > 0)
    			r = mid-1;
            else
                return ans;
    	}
    	return ans;
    }

	int binsearch(vector<int>& arr, int val)
	{	//找第一个大于val的数的下标
		int l = 0, r = arr.size()-1, mid;
		while(l <= r)
		{
			mid = l+((r-l)>>1);
			if(arr[mid] > val)
			{
				if(mid==0 || arr[mid-1] <= val)
					return mid;
				else
					r = mid-1;
			}
			else
				l = mid+1;
		}
		return arr.size();//没找到，全部小于val
	}
};