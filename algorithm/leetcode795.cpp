class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    	int Max = -1, prevPos = -1, count = 0, ans = 0;
    	for(int i = 0; i < A.size(); i++) 
    	{
    		Max = max(Max, A[i]);
    		if(Max>=L && Max<=R)
    		{
    			count += i-prevPos-;
    		}
    		if(A[i] > R)
    		{
    			Max = -1;
    			prevPos = i;
    		}
    	}
    	return count;
    }
};