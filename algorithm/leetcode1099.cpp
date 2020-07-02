class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
    	int i, j, n = A.size(), sum, mindiff = INT_MAX;
    	for(i = 0; i < n-1; ++i)
    	{
    		for(j = i + 1; j < n; ++j)
    		{
    			if(A[i]+A[j] < K && K-A[i]-A[j] < mindiff)
    			{
    				mindiff = K-A[i]-A[j];
    				sum = A[i]+A[j];
    			}
    		}
    	}
    	return mindiff==INT_MAX ? -1 : sum;
    }
};

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
    	sort(A.begin(), A.end());
    	int sum, mindiff = INT_MAX, l, r, mid, t;
    	for(int i = 0; i < A.size(); ++i)
    	{
    		l = 0, r = A.size()-1;
    		t = K-A[i];//找到小于t的最大数
    		while(l <= r)
    		{
    			mid = l+((r-l)>>1);
    			if(A[mid] >= t)
    				r = mid-1;
    			else
    			{
    				if(mid==A.size()-1 || A[mid+1] >= t)
    				{
    					if(mid != i && K-A[mid]-A[i] < mindiff)
    					{
    						mindiff = K-A[mid]-A[i];
    						sum = A[mid]+A[i];
    					}
    					break;
    				}
    				else
    					l = mid+1;
    			}
    		}
    	}
    	return mindiff==INT_MAX ? -1 : sum;
    }
};