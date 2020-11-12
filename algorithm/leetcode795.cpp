class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int l = -1, r = 0, ct1 = 0, ct2 = 0;
        for( ; r < A.size(); ++r)
        {
            if(A[r] <= R)
            {
                ct1 += r-l;
            }
            else
                l = r;
        }
        l = -1;
        for(r = 0; r < A.size(); ++r)
        {
            if(A[r] < L)
            {
                ct2 += r-l;
            }
            else
                l = r;
        }
        return ct1-ct2;
    }
};