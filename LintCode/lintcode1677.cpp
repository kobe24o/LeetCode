unordered_map<int,int> m;// 序号idx，石头能扔的dis距离
struct cmp
{
    bool operator()(const auto& a,const auto& b)
    {
        if(a.second == b.second)//距离一样，小的先出队
            return m[a.first] > m[b.first];
        return a.second > b.second;//距离近的先出队
    }
};

class Solution {
public:
    int getDistance(vector<int> &p, vector<int> &d) {
        if(p.size() == 0)
            return 0;
        bool flag = true;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        // pair ：序号 idx, 石头位置
        for(int i = 0; i < p.size(); ++i)
        {
            m[i] = d[i];// idx，能扔的dis
            q.push(make_pair(i, p[i]));//初始位置
        }

        pair<int,int> tp;
        while(!q.empty())
        {
            tp = q.top();
            q.pop();
            if(flag)
            {
                q.push(make_pair(tp.first, tp.second+m[tp.first]));
            }
            flag = !flag;//奇偶交替
        }
        return tp.second;
    }
};