class NumMatrix {
	vector<vector<int>> mat;
	vector<vector<int>> rowpresum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
    	mat = matrix;
    	rowpresum = matrix;
    	for(int i = 0, j; i < matrix.size(); ++i)
    	{
    		for(j = 1; j < matrix[0].size(); ++j)
    			rowpresum[i][j] = rowpresum[i][j-1] + matrix[i][j];
    	}
    }
    
    void update(int row, int col, int val) {
    	
        mat[row][col] = val;
        rowpresum[row][col] = (col > 0 ? rowpresum[row][col-1] : 0) + val;
    	for(int j = col+1; j < mat[0].size(); ++j)
    		rowpresum[row][j] = rowpresum[row][j-1] + mat[row][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    	int sum = 0;
    	for(int i = row1; i <= row2; ++i)
    	{
    		sum += rowpresum[i][col2] - (col1==0 ? 0 : rowpresum[i][col1-1]);
    	}
    	return sum;
    }
};