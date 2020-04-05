class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        if(dis(xc,yc,x1,y1)<=r*r||dis(xc,yc,x1,y2)<=r*r||dis(xc,yc,x2,y1)<=r*r||dis(xc,yc,x2,y2)<=r*r)
            return true;
        if(x1<=xc && xc <= x2 &&  y1-r <= yc && yc <= y2+r)
            return true;
        if(x1-r<=xc && xc <= x2+r &&  y1 <= yc && yc <= y2)
            return true;
        return false;
    }

    double dis(int xc, int yc, int x, int y)
    {
        return pow((xc-x),2)+pow((yc-y),2);
    }
};