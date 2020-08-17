class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int i, j, area = INT_MAX, s;
        unordered_map<int, unordered_set<int>> m;
        for(auto& p : points)
        	m[p[0]].insert(p[1]);
        for(i = 0; i < points.size(); ++i)
            for(j = i+1; j < points.size(); ++j)
            {
            	if(points[i][0]==points[j][0] || points[i][1]==points[j][1]
                    || !m[points[i][0]].count(points[j][1]) || !m[points[j][0]].count(points[i][1]))
            		//i,j作为对角线，另外两点不存在
            		continue;
                s = abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]);
                if(s < area)
                    area = s;
            }
        return area==INT_MAX ? 0 : area;
    }
};


class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int i, j, area = INT_MAX, s;
        unordered_set<int> m;
        for(auto& p : points)
        	m.insert(p[0]*40001+p[1]);
        for(i = 0; i < points.size(); ++i)
            for(j = i+1; j < points.size(); ++j)
            {
            	if(points[i][0]==points[j][0] || points[i][1]==points[j][1]
                    || !m.count(points[i][0]*40001+points[j][1]) || !m.count(points[j][0]*40001+points[i][1]))
            		//i,j作为对角线，另外两点不存在
            		continue;
                s = abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]);
                if(s < area)
                    area = s;
            }
        return area==INT_MAX ? 0 : area;
    }
};