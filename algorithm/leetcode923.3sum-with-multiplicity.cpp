class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
    	int i, j, k, t, n = A.size(), mod = 1e9+7, count = 0, sum, l, r, n1, n2;
    	sort(A.begin(), A.end());
    	for(i = 0; i < n-2; ++i)
    	{
    		j = i+1, k = n-1;
    		while(j < k)
    		{
    			sum = A[i]+A[j]+A[k];
    			if(sum==target)
    			{
    				l = A[j], r = A[k];
    				n1 = n2 = 0;
    				while(j < k && A[j]==l)
    					n1++,j++;
    				while(j <= k && A[k]==r)
    					n2++,k--;
                    if(l != r)
    				    count += n1*n2;
                    else
                        count += (n1+n2)*(n1+n2-1)/2;
    				count %= mod;
    			}
    			else if(sum < target)
    				j++;
    			else
    				k--;
    		}
    	}
    	return count;
    }
};