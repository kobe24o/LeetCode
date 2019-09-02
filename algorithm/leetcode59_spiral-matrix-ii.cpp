class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > v(n, vector<int>(n,0));
        if(n == 0) 
        	return {};
        int i, num = 0, total = n*n, top = 0, bottom = n-1, left = 0, right = n-1;
        while(num <= total)
        {
        	for(i = left; i <= right; ++i)
        		v[top][i] = ++num;
        	++top;
        	for(i = top; i <= bottom; ++i)
        		v[i][right] = ++num;
        	--right;
        	for(i = right; i >= left; --i)
        		v[bottom][i] = ++num;
        	--bottom;
        	for(i = bottom; i >= top; --i)
        		v[i][left] = ++num;
        	++left;
        }
        return v;
    }
};