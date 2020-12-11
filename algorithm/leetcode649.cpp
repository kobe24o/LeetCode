class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();
        for(int i = 0; i < n; i++)
        {
            if(senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }
        while(!r.empty() && !d.empty())
        {
            if(r.front() < d.front())//序号小的先del对方序号最小的
            {
                d.pop();
                r.push(r.front()+n);// +n 表示下一轮，还
                r.pop();
            }
            else
            {
                r.pop();
                d.push(d.front()+n);// +n 表示下一轮，还
                d.pop();
            }
        }
        return d.empty() ? "Radiant" : "Dire";
    }
};