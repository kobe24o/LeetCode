class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int prevh = 0, prevw = 0, maxh = 0, maxw = 0;
        for(int i = 0; i < hc.size(); ++i)
        {
        	maxh = max(maxh, hc[i]-prevh);
        	prevh = hc[i];
        }
        maxh = max(maxh, h-prevh);
        for(int i = 0; i < vc.size(); ++i)
        {
        	maxw = max(maxw, vc[i]-prevw);
        	prevw = vc[i];
        }
        maxw = max(maxw, w-prevw);
        int s = ((long long) maxh)*maxw%1000000007;
        return s;
    }
};