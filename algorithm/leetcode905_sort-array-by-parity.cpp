class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, count = 0;
        for( ; i < A.size(); ++i)
        {
        	if(A[i]%2 == 0)
        	{
        		if(i != count)
        			swap(A[i], A[count]);
        		++count;
        	}
        }
        return A;
    }
};