class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2)
        	return 0;
        int dp[A.size()] = {0}, differ = A[1]-A[0], sum = 0;
        for(i = 2; i < A.size(); ++i)
        {
        	if(A[i]-A[i-1] == differ)
    		{
    			dp[i] = dp[i-1]+1;
    			sum += dp[i];
    		}
        	else
        		differ = A[i]-A[i-1];
        }
        return sum;
    }
};