class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxlen = 0, count = 0;
        unordered_map<int, int> m;
        for(auto& rec : rectangles)
        {
            int len = min(rec[0], rec[1]);
            ++m[len];
            if(len >= maxlen)
            {
                maxlen = len;
                count = m[len];
            }
        }
        return count;
    }
};