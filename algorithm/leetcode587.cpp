class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> ans;
        for(int i = 0; i < points.size(); ++i)
        {
            while(ans.size()>=2 && dot(ans[ans.size()-2], ans[ans.size()-1],points[i]) < 0)
                ans.pop_back();
            ans.push_back(points[i]);
        }
        for(int i = points.size()-1; i >= 0; --i)
        {
            while(ans.size()>=2 && dot(ans[ans.size()-2], ans[ans.size()-1],points[i]) < 0)
                ans.pop_back();
            ans.push_back(points[i]);
        }
        set<vector<int>> set(ans.begin(), ans.end());
        vector<vector<int>> res(set.begin(), set.end());
        return res;
    }
    int dot(vector<int>& a, vector<int>& b, vector<int>& c)
    {
        int x1 = b[0]-a[0];
        int y1 = b[1]-a[1];
        int x2 = c[0]-b[0];
        int y2 = c[1]-b[1];
        return x1*y2-x2*y1;
    }
};