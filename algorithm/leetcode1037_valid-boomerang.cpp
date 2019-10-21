class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
        int dx1, dx2, dy1, dy2;
        dx1 = p[0][0]-p[1][0];
        dx2 = p[0][0]-p[2][0];
        dy1 = p[0][1]-p[1][1];
        dy2 = p[0][1]-p[2][1];
        if(dx1*dy2 == dx2*dy1)
        	return false;
        return true;
    }
};