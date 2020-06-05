class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
    	sort(A.begin(), A.end());
    	int i, n = A.size(), up, down;
    	int mindis = INT_MAX;
    	for(i = 0; i < n-1; i++)
    	{
    		up = INT_MIN, down = INT_MAX;
    		up = max(A[i]+K, A[n-1]-K);
    		down = min(A[0]+K, A[i+1]-K);
    		mindis = min(mindis, up-down);
    	}
    	return min(mindis, A[n-1]-A[0]);
    }
};