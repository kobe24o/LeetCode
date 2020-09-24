class Solution {

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> time(n, 0);
        stack<pair<int,int>> s;// id, time
        int id, t, period = 0, p1, p2;
        for(auto& log : logs)
        {
            p1 = log.find(':');
            id = stoi(log.substr(0,p1));//提取id
            p2 = log.find_last_of(':');
            t = stoi(log.substr(p2+1));//提取t
            if(log[p1+1]=='e')//当前是结束，那么栈顶是开始
            {
                period = t-s.top().second+1;//当前函数的执行时间
                time[id] += period;//函数执行时间增加
                s.pop();//弹栈
                if(!s.empty())//栈不为空，说明有外层函数
                    // 外层函数的时间要减去内层执行时间
                    time[s.top().first] -= period;
            }
            else
            {
                s.push({id, t});
            }
        }
        return time;
    }
};