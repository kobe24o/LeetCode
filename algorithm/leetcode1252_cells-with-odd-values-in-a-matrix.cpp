class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int row[n] = {0}, column[m] = {0};
        for(auto &xy : indices)
        {
        	row[xy[0]]++;
        	column[xy[1]]++;
        }
        int countR = 0, countC = 0;
        for(auto & i : row)
        	if(i%2)
        		countR++;
    	for(auto & i : column)
        	if(i%2)
        		countC++;
    	return countR*m + countC*n - 2*countR*countC;
    }
};