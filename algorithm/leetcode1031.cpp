class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size(), i, j, k, maxsum = 0, sum1, sum2;
        vector<int> sum(A);
        for(i = 1; i < n; i++) 
            sum[i] = sum[i-1]+A[i];
        for(i = 0; i <= n-L; i++)
        {
            sum1 = sum[i+L-1] - (i > 0 ? sum[i-1] : 0);
            for(j = 0; j+M-1 < i; j++)
            {
                sum2 = sum[j+M-1] - (j > 0 ? sum[j-1] : 0);
                maxsum = max(maxsum, sum1+sum2);
            }
            for(j = i+L; j+M-1 < n; j++)
            {
                sum2 = sum[j+M-1] - (j > 0 ? sum[j-1] : 0);
                maxsum = max(maxsum, sum1+sum2);
            }
        }
        return maxsum;
    }
};

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size(), i;
        vector<int> sum(A);
        for(i = 1; i < n; i++) 
            sum[i] = sum[i-1]+A[i];
        int maxsum = sum[L+M-1], maxsumL = sum[L-1], maxsumM = sum[M-1];
        for(i = L+M; i < n; i++)
        {
            maxsumL = max(maxsumL, sum[i-M]-sum[i-M-L]);
            maxsumM = max(maxsumM, sum[i-L]-sum[i-L-M]);
            maxsum = max(maxsum, 
                            max(maxsumL+sum[i]-sum[i-M], 
                                maxsumM+sum[i]-sum[i-L]));
        }
        return maxsum;
    }
};