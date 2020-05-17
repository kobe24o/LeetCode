class Solution {
	double cx, cy;//圆心坐标
public:
    int numPoints(vector<vector<int>>& points, int r) {
    	int x1, x2, y1, y2;
        double dx, dy;
    	int i, j, k, count, maxcount=1, n = points.size();
    	for(i = 0; i < n; ++i)
    	{
    		x1 = points[i][0];
    		y1 = points[i][1];
    		for(j = 0; j < n; ++j)//i,j为圆上的点
    		{
                if(i == j)
                    continue;
    			x2 = points[j][0];
    			y2 = points[j][1];
    			count = 2;
		    	int d_d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		    	if(d_d > 4*r*r) continue;
                count = 0;
		    	cx = (x1+x2)/2.0-(y2-y1)*sqrt((r*r-d_d/4.0)/d_d), 
                cy = (y1+y2)/2.0+(x2-x1)*sqrt((r*r-d_d/4.0)/d_d);
    			for(k = 0; k < n; ++k)
    			{
    				dx = points[k][0]-cx;
    				dy = points[k][1]-cy;
    				if(dx*dx+dy*dy <= r*r)
    					count++;
    			}
    			maxcount = max(maxcount, count);
                count = 0;
		    	cx = (x1+x2)/2.0+(y2-y1)*sqrt((r*r-d_d/4.0)/d_d), 
                cy = (y1+y2)/2.0-(x2-x1)*sqrt((r*r-d_d/4.0)/d_d);
    			for(k = 0; k < n; ++k)
    			{
    				dx = points[k][0]-cx;
    				dy = points[k][1]-cy;
    				if(dx*dx+dy*dy <= r*r)
    					count++;
    			}
    			maxcount = max(maxcount, count);
    		}
    	}
    	return maxcount;
    }
};