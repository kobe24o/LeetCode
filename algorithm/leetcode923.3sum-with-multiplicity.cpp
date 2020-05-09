class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
    	int i, j, k, t, n = A.size(), mod = 1e9+7;
    	sort(A.begin(), A.end());
    	i = 0, j = n-1;
    	while(i < j)
    	{
    		t = target-(A[i]+A[j]);
    		for(k = i+1; )
    	}
    }
};