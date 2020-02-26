class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int i, j, a, b;
    	for(i = 0; i < matrix.size(); ++i)
    	{
    		for(j = 0; j < i; ++j)
    			swap(matrix[i][j], matrix[j][i]);
    	}
    	for(i = 0; i < matrix.size(); ++i)
    	{
    		a = 0, b = matrix[0].size();
    		while(a < b)
    			swap(matrix[i][a], matrix[i][b]);
    	}
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int i, j, n = matrix.size();
    	for(i = 0; i < n/2; ++i)
    	{
    		for(j = i; j < n-i-1; ++j)
    		{
    			swp(matrix[i][j], matrix[n-1-j][i]);
    			swp(matrix[n-1-j][i], matrix[n-1-i][n-1-j]);
    			swp(matrix[n-1-i][n-1-j], matrix[j][n-1-i]);
    		}
    	}
    }

    void swp(int&a, int&b)
    {
    	a ^= b ^= a ^= b;
    }
};