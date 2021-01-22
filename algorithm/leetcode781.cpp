class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for(auto a : answers)
            m[a+1]++;//有a+1个人一个颜色，多少个兔子这么说了
        int ans = 0;
        for(auto &mi : m)
        {
            int tellnum = mi.first;//这么多兔子是一种颜色
            int people = mi.second;//有多少个兔子这么说了
            //贪心，让他们组成同一种颜色，如 5个兔子说有5个兔子颜色一样
            // 那么这5个兔子组成一种颜色即可，答案是5只
            // 6个兔子说有5个兔子颜色一样，把5个颜色一样的拿走
            // 还剩下的1只兔子肯定是别的颜色，他还有4个同伴没有回答，答案是10只
            ans += ceil(double(people)/tellnum)*tellnum;
        }
        return ans;
    }
};