class SubrectangleQueries {
    vector<vector<int>> v;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        v = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        int i,j;
        for(i = row1; i <= row2; ++i)
            for(j = col1; j <= col2; ++j)
                v[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return v[row][col];
    }
};

class SubrectangleQueries {
    vector<vector<int>> record;
    vector<vector<int>> v;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        v = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        record.push_back({row1,col1,row2,col2,newValue});
    }
    
    int getValue(int row, int col) {
        for(int i = record.size()-1; i >= 0; --i)
        {
            if(row>=record[i][0] && row<=record[i][2] && col>=record[i][1] && col<=record[i][3])
                return record[i][4];
        }
        return v[row][col];
    }
};