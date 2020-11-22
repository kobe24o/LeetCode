class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),[](auto&a, auto&b) {
            return a[1]-a[0] > b[1]-b[0];//差值大的优先
        });
        int val = 0, presum = 0;
        for(int i = 0; i < tasks.size(); ++i) 
        {
            val = max(val, presum+tasks[i][1]);
            presum += tasks[i][0];
        }
        return val;
    }
};

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),[](auto&a, auto&b) {
            return a[1]-a[0] > b[1]-b[0];//差值大的优先
        });
        int val = 0, delta = 0, sum = 0;
        for(int i = 0; i < tasks.size(); ++i) 
            sum += tasks[i][0];
        int s = sum;
        for(int i = 0; i < tasks.size(); ++i) 
        {
            if(s-tasks[i][1] < 0)
            {
                delta += tasks[i][1]-s;
                s += tasks[i][1]-s;
            }
            s -= tasks[i][0];
        }
        return sum+delta;
    }
};