class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    	int i, prex = points[0][0], prey = points[0][1], dis = 0;
        for(i = 1; i < points.size(); ++i)
        {
        	dis += max(abs(prex - points[i][0]),abs(prey - points[i][1]));
        	prex = points[i][0];
        	prey = points[i][1];
        }
        return dis;
    }
};