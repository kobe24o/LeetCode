class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.empty())
        	return A;
        int i, j, n;
        for(i = 0; i < A.size(); ++i)
        {
        	n = A[i].size();
        	for(j = 0; j < 2*n; j += 2)
        	{
        		A[i].insert(A[i].begin(),!A[i][j]);
        	}
        	A[i].erase(A[i].begin()+n, A[i].end());
        }
        return A;
    }
};