class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& ret) {
        set<pair<int,int>> s;
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN, area = 0;
        for(int i = 0; i < ret.size(); ++i)
        {
            x1 = min(ret[i][0],x1);
            x2 = max(ret[i][2],x2);
            y1 = min(ret[i][1],y1);
            y2 = max(ret[i][3],y2);
            area += (ret[i][2]-ret[i][0])*(ret[i][3]-ret[i][1]);

            if(s.find({ret[i][0],ret[i][1]})==s.end())
            	s.insert({ret[i][0],ret[i][1]});
            else
            	s.erase({ret[i][0],ret[i][1]});

            if(s.find({ret[i][2],ret[i][3]})==s.end())
            	s.insert({ret[i][2],ret[i][3]});
            else
            	s.erase({ret[i][2],ret[i][3]});

            if(s.find({ret[i][0],ret[i][3]})==s.end())
            	s.insert({ret[i][0],ret[i][3]});
            else
            	s.erase({ret[i][0],ret[i][3]});

            if(s.find({ret[i][2],ret[i][1]})==s.end())
            	s.insert({ret[i][2],ret[i][1]});
            else
            	s.erase({ret[i][2],ret[i][1]});
        }

        if(s.size() !=4 || !s.count({x1,y1}) || !s.count({x1,y2}) || !s.count({x2,y1}) || !s.count({x2,y2}))
        	return false;
        return area == (x2-x1)*(y2-y1);
    }
};