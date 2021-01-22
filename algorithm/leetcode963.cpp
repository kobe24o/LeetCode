class point{
public:
	int x, y;
	point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
    bool operator<(point a) const
    {
        return (x==a.x && y < a.y) || (x < a.x);
    }
};
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
    	map<int,map<point,vector<point>>> m;// square len, midpoint, point
    	int n = points.size(), x1,x2,y1,y2,x3,y3,d;
    	int midx, midy;
    	for(int i = 0; i < n; ++i)
    	{
    		for(int j = i+1; j < n; ++j)
    		{
    			x1 = points[i][0];
    			y1 = points[i][1];
    			x2 = points[j][0];
    			y2 = points[j][1];
    			midx = (x1+x2);//不除以2
    			midy = (y1+y2);
    			d = dis(x1,y1,x2,y2);
    			m[d][point(midx, midy)].push_back(point(x1,y1));
    		}
    	}
    	double area = INT_MAX;
    	int dx1,dy1,dx2,dy2;
    	for(auto it = m.begin(); it != m.end(); ++it)
    	{
    		for(auto it1 = it->second.begin(); it1 != it->second.end(); ++it1)
    		{
    			midx = it1->first.x;
    			midy = it1->first.y;
    			for(int i = 0; i < it1->second.size(); ++i)
    			{
    				x1 = it1->second[i].x;
    				y1 = it1->second[i].y;
    				x2 = midx-x1;
    				y2 = midy-y1;
    				for(int j = i+1; j < it1->second.size(); ++j)
    				{
    					x3 = it1->second[j].x;
    					y3 = it1->second[j].y;
    					dx1 = x1-x3, dy1 = y1-y3;
    					dx2 = x2-x3, dy2 = y2-y3;
    					if(dx1*dx2+dy1*dy2==0)
    					{
    						area = min(area, sqrt(dx1*dx1+dy1*dy1)*sqrt(dx2*dx2+dy2*dy2));
    					}
    				}
    			}
    		}
    	}
    	return area == INT_MAX ? 0 : area;
    }
    int dis(int x1, int y1, int x2, int y2)
    {
    	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
};