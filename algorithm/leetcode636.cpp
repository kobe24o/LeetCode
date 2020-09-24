class Solution {

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> time(n, 0);
        stack<pair<int,int>> s;
        int id, t, period = 0, p1, p2;
        for(auto& log : logs)
        {
            p1 = log.find(':');
            id = stoi(log.substr(0,p1));
            p2 = log.find_last_of(':');
            t = stoi(log.substr(p2+1));
            if(log[p1+1]=='e')//当前是结束，那么栈顶是开始
            {
                period = t-s.top().second+1;
                time[id] += period;
                s.pop();
                if(!s.empty())
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