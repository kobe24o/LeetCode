class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), i, j;
        int r[m] = {0}, c[n] = {0};
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(matrix[i][j] == 0)
        		{
        			r[i] = 1;
        			c[j] = 1;
        		}
        	}
        }

        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(r[i] == 1 || c[j] == 1)
        			matrix[i][j] = 0;
        	}
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r0 = 0, c0 = 0;//记录第1行和第一列是否有0
        //遍历除了1行1列外的元素，用第1行1列作为标记位
        int i, j, m = matrix.size(), n = matrix[0].size();
        for(i = 0; i < m; ++i)
        	if(matrix[i][0] == 0)
        	{
        		c0 = 1;
        		break;
        	}

    	for(j = 0; j < n; ++j)
        	if(matrix[0][j] == 0)
        	{
        		r0 = 1;
        		break;
        	}
    	for(i = 1; i < m; ++i)
        {
        	for(j = 1; j < n; ++j)
        	{
        		if(matrix[i][j] == 0)
        		{
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }
        for(i = 1; i < m; ++i)
        	if(matrix[i][0] == 0)
        	{
        		for(j = 1; j < n; ++j)
        			matrix[i][j] = 0;
        	}
    	for(j = 1; j < n; ++j)
        	if(matrix[0][j] == 0)
        	{
        		for(i = 1; i < m; ++i)
        			matrix[i][j] = 0;
        	}
    	if(c0)
    		for(i = 0; i < m; ++i)
        		matrix[i][0] = 0;
    	if(r0)
	    	for(j = 0; j < n; ++j)
	        	matrix[0][j] = 0;
    }
};