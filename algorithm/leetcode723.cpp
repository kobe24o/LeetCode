class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& b) {
    	int m = b.size(), n = b[0].size(), i, j, up, down;
    	for(i = 0; i < m; ++i)//横向检查
    		for(j = 0; j < n-2; ++j)
    		{
    			if(abs(b[i][j])==abs(b[i][j+1]) && abs(b[i][j+1])==abs(b[i][j+2]))
    				b[i][j] = b[i][j+1] = =b[i][j+2] = -abs(b[i][j]);//标记为负的
    		}
    	for(j = 0; j < n; ++j)//纵向检查
    		for(i = 0; i < m-2; ++i)
    		{
    			if(abs(b[i][j])==abs(b[i+1][j]) && abs(b[i+1][j])==abs(b[i+2][j]))
    				b[i][j] = b[i+1][j] = =b[i+2][j] = -abs(b[i][j]);//标记为负的
    		}
    	for(i = 0; i < m; ++i)//标记为0
    		for(j = 0; j < n; ++j)
    			if(b[i][j] < 0)
    				b[i][j] = 0;
    	for(j = 0; j < n; ++j)//纵向掉落
    	{
    		down = up = m-1;//最底层
    		for(i = 0; i < m-2; ++i)
    		{	//双指针搬移数据
    			
    		}
    	}
    }
};