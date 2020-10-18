class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int n = towers.size();
        int q[51][51];
        memset(q, 0, sizeof(q));
        int maxs = 0, x, y;
        for(int i = 0; i <= 50; ++i) 
        {
            for(int j = 0; j <= 50; ++j)
            {
                for(int k = 0; k < n; ++k)
                {

                    int d = (towers[k][0]-i)*(towers[k][0]-i)
                          +(towers[k][1]-j)*(towers[k][1]-j);
                    if(d > radius*radius)
                        continue;
                    q[i][j] += towers[k][2]/(1+sqrt(d));
                }
                if(q[i][j] > maxs)
                {
                    maxs = q[i][j];
                    x = i, y = j;
                }
            }
        }
        return {x, y};
    }
};