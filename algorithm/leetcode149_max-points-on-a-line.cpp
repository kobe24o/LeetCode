class Solution {
public:
    int gcd(int a, int b) //求最大公约数
    {
        int g;
        while(b != 0)
        {
            g = a%b;
            a = b;
            b = g;
        }
        return a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxCount = 2, same = 0, count = 0;
        if (n <= 2) 
            return n;
        map<pair<int, int>, int> m;//最简斜率，<dx, dy>, 计数
        int i, j, dx, dy, g;
        for(i = 0; i < n; ++i)
        {
            m.clear();
            same = 1;//i点自己
            count = 0;
            for(j = 0; j < n; ++j) 
            {
                if(j == i)
                    continue;
                dx = points[i][0] - points[j][0];
                dy = points[i][1] - points[j][1];
                if(dx == 0 && dy == 0) //与i相同的点
                    ++same;
                else 
                {
                    g = gcd(abs(dx), abs(dy));//求最大公约数，参数取正数
                    m[{dx/g, dy/g}]++;//经过i点，斜率一样的点，计数+1
                }
            }
            for(auto p : m)//遍历经过i点的所有直线
                if(p.second > count)//经过i点的所有直线中某个斜率的最多
                    count = p.second;
            if (count+same > maxCount) //最多的点数 count+same 在一条直线上
                maxCount = count + same;
        }
        return maxCount;
    }
};