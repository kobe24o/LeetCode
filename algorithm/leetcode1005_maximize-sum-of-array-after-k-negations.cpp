class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i, sum = 0, minN = INT_MAX, idx;
        for(i = 0; i < A.size(); ++i)
        	if(abs(A[i]) < minN)
        	{
        		minN = abs(A[i]); 
        		idx = i;
        	}
        for(i = 0; K>0 && i < A.size(); ++i)
        {
        	if(A[i] < 0)
        	{
        		A[i] = -A[i];
        		K--;
        	}
        }
		if(K%2 == 1)
			A[idx] = -A[idx];
        for(i = 0; i < A.size(); ++i)
        	sum += A[i];
        return sum;
    }
};