class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min = INT_MAX, max = INT_MIN, i;
        for(i = 0; i < A.size(); ++i) 
        {
        	if(A[i] > max)
        		max = A[i];
        	if(A[i] < min)
        		min = A[i];
        }
        if(min+K <= max-K)
        	return max-K-min-K;
        else
        	return 0;
    }
};