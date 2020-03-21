class Solution {    //超时
public:
    int timeToFlowerTree(vector<int> &father, vector<int> &time) {
        // write your code here
        multimap<int,int> m;//father， self
        int n = father.size(), id, t, maxt =0 ;
        for(int i = 1; i < n; ++i)
            m.insert(make_pair(father[i],i));
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {   
            id = q.front().first;
            t = q.front().second;
            maxt = max(maxt, t);
            q.pop();
            auto s = m.lower_bound(id);
            auto e = m.upper_bound(id);
            for(; s != e; ++s)
            {
                q.push(make_pair(s->second,t+time[s->second]));
            }
        }
        return maxt;
    }
};

class Solution {
public:
    int timeToFlowerTree(vector<int> &father, vector<int> &time) {
        // write your code here
        
        int n = father.size(), id, t, maxt =0 ,i;
        vector<vector<int>> map(n);
        for(i = 1; i < n; ++i)
            map[father[i]].push_back(i);
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {   
            id = q.front().first;
            t = q.front().second;
            maxt = max(maxt, t);
            q.pop();
            for(i = 0; i < map[id].size(); ++i)
            {
                q.push(make_pair(map[id][i], t+time[map[id][i]]));
            }
            
        }
        return maxt;
    }
};