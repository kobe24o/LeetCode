class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0, y = 0, d = 0, n = 4;
        while(n--)
            for(char ch : instructions) 
            {
                if(ch == 'G')
                {
                    x += dir[d][0];
                    y += dir[d][1];
                }
                else if(ch == 'L')
                    d = (d-1+4)%4;
                else
                    d = (d+1)%4;
            }
        return !x && !y;
    }
};