class Solution {
    set<int> pos;
public:
    int maxDistance(vector<int>& position, int m) {
        int l = 1, r = 1e9+1, dis, ans;
        for(auto i : position)
            pos.insert(i);
        while(l <= r)
        {
            dis = (l+r)/2;
            if(canPutM(position, m, dis))
            {
                ans = dis;
                l = dis+1;
            }
            else
                r = dis-1;
        }
        return ans;
    }

    bool canPutM(vector<int>& position, int m, int dis)
    {
        int count = 1, p = *pos.begin();
        auto it = pos.lower_bound(p+dis);
        while(it != pos.end() && count < m)//放下了几个满足dis间距的球
        {
            ++count;
            p = *it;
            it = pos.lower_bound(p+dis);
        }
        return count == m; //可以放下这么多球
    }
};