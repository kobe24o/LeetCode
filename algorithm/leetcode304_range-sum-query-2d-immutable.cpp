class NumMatrix {
	vector<vector<int>> sumofrows;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int r = matrix.size(), c = matrix[0].size(), i, j, sum = 0;
        vector<int> temp(c,0);
        for(i = 0; i < r; i++)
        {
        	sum = 0;
        	for(j = 0; j < c; j++)
        	{
        		sum += matrix[i][j];
        		temp[j] = sum;
        	}
        	sumofrows.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(sumofrows.empty())
            return 0;
        int i, j, sum = 0;
        if(col1 != 0)
            for(i = row1; i <= row2; i++)
            {
                sum += sumofrows[i][col2]-sumofrows[i][col1-1];
            }
        else
            for(i = row1; i <= row2; i++)
            {
                sum += sumofrows[i][col2];
            }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
class NumMatrix {
	vector<vector<int>> sumofrows;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int r = matrix.size(), c = matrix[0].size(), i, j;
        sumofrows = vector<vector<int>> (r+1, vector<int>(c+1, 0));
        for(i = 0; i < r; i++)
        {
        	for(j = 0; j < c; j++)
        	{
        		sumofrows[i+1][j+1] = sumofrows[i+1][j]+sumofrows[i][j+1]+matrix[i][j]-sumofrows[i][j];
        	}
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(sumofrows.empty())
            return 0;
        return sumofrows[row2+1][col2+1] - sumofrows[row1][col2+1] - sumofrows[row2+1][col1] + sumofrows[row1][col1];
    }
};