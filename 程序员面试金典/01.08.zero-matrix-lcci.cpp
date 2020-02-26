class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	if(matrix.size()==0 || matrix[0].size() == 0)
    		return;
    	//先遍历除第一行，第一列外的区域
    	int i, j, m = matrix.size(), n = matrix[0].size();
    	bool r0c0Zero = (matrix[0][0] == 0);
        bool r0 = 0, c0 = 0;
        if(!r0c0Zero)
        {
            for(i = 1; i < m; i++)
                if(matrix[i][0] == 0)
                {
                    c0 = true;//第一列需要后序变0
                    break;
                }
            for(j = 1; j < n; j++)
                if(matrix[0][j] == 0)
                {
                    r0 = true;//第一行需要后序变0
                    break;
                }
        }
    	for(i = 1; i < m; i++)
    		for(j = 1; j < n; j++)
    		{
    			if(matrix[i][j] == 0)
    			{
    				matrix[0][j] = 0;//用第一行标记是否删除列
    				matrix[i][0] = 0;//用第一列标记是否删除行
    			}
    		}
		for(i = 1; i < m; i++)
		{
			if(matrix[i][0] == 0)//删除行
				for(j = 1; j < n; j++)
					matrix[i][j] = 0;
		}
		for(j = 1; j < n; j++)
		{
			if(matrix[0][j] == 0)//删除列
				for(i = 1; i < m; i++)
					matrix[i][j] = 0;
		}
		if(r0c0Zero)//删除第一行，第一列
		{
			for(i = 1; i < n; i++)
				matrix[0][i] = 0;
			for(i = 1; i < m; i++)
				matrix[i][0] = 0;
		}
		else
		{
			if(r0)//删除第一行
			{
				for(j = 0; j < n; j++)
	        		matrix[0][j] = 0;
			}
			if(c0)//删除第一列
			{
				for(i = 0; i < m; i++)
            		matrix[i][0] = 0;
			}
		}
    }
};