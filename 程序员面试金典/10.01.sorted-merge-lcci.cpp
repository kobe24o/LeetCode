class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
    	int i = 0, j = 0, count = m+n;
    	while(m && n)
    	{
    		if(A[i] <= B[j])
    			i++,m--;
    		else
    		{
    			A.insert(A.begin()+i, B[j++]);
    			n--;
    			i++;
    		}
    	}
    	while(n--)
    		A[i++] = B[j++];
    	while(A.size() > count)
    		A.pop_back();
    }
};