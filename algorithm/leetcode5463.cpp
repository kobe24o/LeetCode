class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
    	int n = positions.size(), k;
        double x0, y0, xi = 0, yi = 0, nx, ny;
    	for(int i = 0; i < n; ++i)
    	{
    		xi += positions[i][0];
    		yi += positions[i][1];
    	}
    	x0 = xi/n;
    	y0 = yi/n;//均值作为初始值
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	double eps = 1e-6, step = 100, d, dis = calSumDis(x0,y0,positions);
    	while(step > eps)
    	{
    		bool down = false;
    		for(k = 0; k < 4; ++k)
    		{
    			nx = x0 + dir[k][0]*step;
    			ny = y0 + dir[k][1]*step;
    			d = calSumDis(nx, ny, positions);
    			if(d < dis)
    			{
    				dis = d;
    				x0 = nx;
    				y0 = ny;
    				down = true;
                    break;
    			}
    		}
            if(!down)
    			step /= 2.0;
    	}
    	return dis;
    }

	double calSumDis(double x0, double y0, vector<vector<int>>& p)
	{
		double d = 0.0;
		for(auto& pi : p)
			d += sqrt((x0-pi[0])*(x0-pi[0])+(y0-pi[1])*(y0-pi[1]));
		return d;
	}
};