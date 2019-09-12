class Solution {
public:
    bool isMonotonic(vector<int>& A) {
    	if(A.size() <= 2)
    		return true;
    	int i = 1, j;
    	bool up;
    	while(i < A.size() && A[i] == A[i-1])
    		i++;
    	if(i < A.size())
    	{
    		if(A[i] > A[i-1])
    			up = true;
    		else
    			up = false;
    	}
        for(j = i+1; j < A.size(); ++j)
        {      	
        	if(up && A[j] < A[j-1])
        	{
        		return false;
        	}
        	if(!up && A[j] > A[j-1])
        		return false;
        }
        return true;
    }
};