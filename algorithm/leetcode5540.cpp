class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> arr;
        for(auto &p : points)
            arr.push_back(p[0]);
        sort(arr.begin(), arr.end());
        int maxw = 0;
        for(int i = 1; i < arr.size(); i++)
        {
            maxw = max(maxw, arr[i]-arr[i-1]);
        }
        return maxw;
    }
};