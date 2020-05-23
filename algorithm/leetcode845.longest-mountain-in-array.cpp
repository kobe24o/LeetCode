class Solution {
public:
    int longestMountain(vector<int>& A) {
    	if(A.size() < 3)
    		return 0;
    	int i, l, r, len, maxlen = 0;
    	for(i = 1; i < A.size()-1; ++i)
    	{
    		if(A[i-1] < A[i] && A[i] > A[i+1])
    		{
    			len = 1, l = r = i;
    			while(l >= 1 && A[l-1] < A[l])
    			{
    				len++;
    				l--;
    			}
    			while(r < A.size()-1 && A[r] > A[r+1])
    			{
    				len++;
    				r++;
    			}
    			maxlen = max(maxlen, len);
    			i = r;
    		}
    	}
    	return maxlen;
    }
};