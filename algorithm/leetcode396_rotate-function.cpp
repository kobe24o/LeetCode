class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int F_i = 0, diff = 0, ans = INT_MIN, n = A.size();
        for(int i = 0, k = 0; i < n; ++i,++k)
        {
        	F_i += k*A[i];
        	if(i != A.size()-1)
        		diff += A[i];
        	else
        		diff -= i*A[i];
        }
        ans = F_i;
        for(int i = 1; i < n; ++i)
        {
        	F_i += diff;
        	if(F_i > ans)
        		ans = F_i;
        	diff += A.size()*(A[n-i]-A[n-i-1]);
        }
        return ans;
    }
};