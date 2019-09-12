class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int i,j = A.size()-1,k;
        vector<int> ans;
        while(j>=1)
        {
        	i = findmax(A,j);
        	if(i != 0)
    		{
    			ans.push_back(i+1);
    			reverse(A.begin(), A.begin()+i+1);
    		}
    		ans.push_back(j+1);
    		reverse(A.begin(), A.begin()+j+1);
    		--j;
        }
        return ans;
    }
    int findmax(vector<int>& A, int &j)
    {
    	int m = INT_MIN, idx;
    	for(int i=0; i<=j; ++j)
    		if(A[i] > m)
    		{
    			m = A[i];
    			idx = i;
    		}
		return idx;
    }
};