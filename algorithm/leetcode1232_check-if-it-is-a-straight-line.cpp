class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cd) {
        int dy, dx, i;
        dy = cd[0][1]-cd[1][1];
        dx = cd[0][0]-cd[1][0];
        for(i = 1; i < cd.size(); ++i)
            if(dy*(cd[i][0]-cd[0][0]) != dx*(cd[i][1]-cd[0][1]))
                return false;
        return true;
    }
};