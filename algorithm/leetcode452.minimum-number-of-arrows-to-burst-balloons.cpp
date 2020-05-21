class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    	if(points.empty()) return 0;
        sort(points.begin(), points.end(),[&](auto a, auto b){
        	return a[1] < b[1];
        });
        int i = 0, pos = points[0][1], count = 1;
        while(i < points.size())
        {
        	while(i < points.size() && points[i][0] <= pos)
        		i++;
        	if(i < points.size())
        	{
        		count++;
        		pos = points[i][1];
        	}
        }
        return count;
    }
};