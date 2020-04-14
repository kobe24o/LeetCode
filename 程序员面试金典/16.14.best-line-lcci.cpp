class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
    	int i, j, g, dx, dy, maxCount = 0, n = points.size();
    	double k, b;

    	unordered_map<double,unordered_map<double,vector<int>>> m;
    	unordered_map<double,vector<int>> v;
    	vector<int> ansline;
    	for(i = 0; i < n-1; ++i)
    	{
    		for(j = i+1; j < n; ++j)
    		{
    			dx = points[j][0]-points[i][0];
    			dy = points[j][1]-points[i][1];
    			if(dx==0)
    			{
    				if(v[double(points[i][0])].empty())
    					v[double(points[i][0])].push_back(i);
    				v[double(points[i][0])].push_back(j);
    			}
    			else if(dy==0)
    			{
    				if(m[0.0][double(points[i][1])].empty())
    					m[0.0][double(points[i][1])].push_back(i);
    				m[0.0][double(points[i][1])].push_back(j);
    			}
    			else
    			{
    				k = double(dy)/dx;
    				b = points[i][0]-points[i][1]/k;
    				if(m[k][b].empty())
    					m[k][b].push_back(i);
    				m[k][b].push_back(j);
    			}
    		}
    	}
    	for(auto& mi : m)
    	{
    		for(auto& mii : mi.second)
    		{
    			for(auto& miii : mii.second)
    			{
    				if(miii.size() > maxCount)
    				{
    					maxCount = miii.size();
    					ansline = miii;
    				}
    			}
    		}
    	}
    	for(auto& vi : v)
    	{
    		if(vi.second.size() > maxCount)
			{
				maxCount = vi.second.size();
				ansline = vi.second;
			}
    	}
    	return {ansline[0],ansline[1]};
    }
};