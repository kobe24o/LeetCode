class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        long long cur, prev = 0;
        int i, n = points.size();
        long long x1, y1, x2, y2;
        for(i = 0; i < n; i++) 
        {
            x1 = points[i][0]-points[(i+1)%n][0];
            y1 = points[i][1]-points[(i+1)%n][1];
            x2 = points[i][0]-points[(i+2)%n][0];
            y2 = points[i][1]-points[(i+2)%n][1];
            cur = x1*y2-x2*y1;
            if(cur != 0)
            {
                if(cur*prev < 0)
                    return false;
                prev = cur;
            }
        }
        return true;
    }
};