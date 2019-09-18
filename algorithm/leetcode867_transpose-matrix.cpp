class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int i, j;
        vector<int> temp;
        vector<vector<int>> ans;
        for(j = 0; j < A[0].size(); ++j)
        {
        	temp.clear();
        	for(i = 0; i < A.size(); ++i)
        	{
        		temp.push_back(A[i][j]);
        	}
        	ans.push_back(temp);
        }
        return ans;
    }
};