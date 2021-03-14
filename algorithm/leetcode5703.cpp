// 超时
struct cmp{
    bool operator()(vector<int>& a, vector<int>& b) const
    {
        return double(a[0]+1)/(a[1]+1)-double(a[0])/a[1] < double(b[0]+1)/(b[1]+1)-double(b[0])/b[1];
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> q;
        for(auto& c : classes)
            q.push(c);
        vector<int> c;
        while(extraStudents--)
        {
            c = q.top();
            q.pop();
            q.push({c[0]+1, c[1]+1});
        }
        double ans = 0;
        while(!q.empty())
        {
            ans += q.top()[0]/double(q.top()[1]);
            q.pop();
        }
        return ans/classes.size();
    }
};

// 更改写法
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double,int,int>> q;
        for(auto& c : classes)
            q.push(tuple(delta(c[0], c[1]), c[0], c[1]));
        while(extraStudents--)
        {
            auto [d, x, y] = q.top();
            q.pop();
            q.push(tuple(delta(x+1, y+1), x+1, y+1));
        }
        double ans = 0;
        while(!q.empty())
        {
            auto [d, x, y] = q.top();
            q.pop();
            ans += x/double(y);
        }
        return ans/classes.size();
    }
    double delta(int x, int y){
        return double(x+1)/(y+1)-double(x)/y;
    }
};