class Solution {
    int lx2,rx2,by2,uy2;
    int lx1,rx1,by1,uy1;
    int dx1, dy1, dx2, dy2;
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        lx2 = min(start2[0],end2[0]);
        rx2 = max(start2[0],end2[0]);
        by2 = min(start2[1],end2[1]);
        uy2 = max(start2[1],end2[1]);
        lx1 = min(start1[0],end1[0]);
        rx1 = max(start1[0],end1[0]);
        by1 = min(start1[1],end1[1]);
        uy1 = max(start1[1],end1[1]);

        dx1 = start1[0]-end1[0];
        dy1 = start1[1]-end1[1];
        dx2 = start2[0]-end2[0];
        dy2 = start2[1]-end2[1];
        if(dx1*dy2==dx2*dy1)//平行
        {
            vector<vector<int>> ans;
            if(inline2(start1[0],start1[1],start2[0],start2[1]))
            {
                ans.push_back({start1[0],start1[1]});
            }
            if(inline2(end1[0],end1[1],start2[0],start2[1]))
            {
                ans.push_back({end1[0],end1[1]});
            }
            if(inline1(start2[0],start2[1],start1[0],start1[1]))
            {
                ans.push_back({start2[0],start2[1]});
            }
            if(inline1(end2[0],end2[1],start1[0],start1[1]))
            {
                ans.push_back({end2[0],end2[1]});
            }
            if(ans.size()>1)
                sort(ans.begin(), ans.end());
            if(ans.size())
                return {double(ans[0][0]),double(ans[0][1])};
            return {};
        }
        else
        {
            double x = double(dx1*dx2*(start2[1]-start1[1])+dx2*dy1*start1[0]-dx1*dy2*start2[0])/(dx2*dy1-dx1*dy2);
            double y = double(dy1*dy2*(start2[0]-start1[0])+dx1*dy2*start1[1]-dx2*dy1*start2[1])/(dx1*dy2-dx2*dy1);
            if(inline1(x,y,start1[0],start1[1])&&inline2(x,y,start2[0],start2[1]))
                return {x,y};
            return {};
        }

    }

    bool inline1(double x, double y, int x0, int y0)
    {
        return (lx1<=x && x<=rx1 && by1<=y && y<=uy1 && (abs(dx1*(y-y0)-dy1*(x-x0))<0.000001));
    }
    bool inline2(double x, double y, int x0, int y0)
    {
        return (lx2<=x && x<=rx2 && by2<=y && y<=uy2 && (abs(dx2*(y-y0)-dy2*(x-x0))<0.000001));
    }
};