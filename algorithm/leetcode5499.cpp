class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
    	int n = arr.size(), i, j, len, count;
    	if(m*k > n) return false;
    	for(int l = 0; l <= n-m*k; ++l) 
    	{
    		count = 1, i = l, j = l+m, len = m;
    		while(j < n && count < k)
    		{
    			if(arr[j] == arr[i])
    				i++,j++;
    			else
    				break;
    			if(i == l+m)
    				i = l, count++;
    		}
    		if(count >= k)
    			return true;
    	}
    	return false;
    }
};