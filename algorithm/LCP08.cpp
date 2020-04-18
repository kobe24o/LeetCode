struct cmp1//自定义map排序规则
{
    bool operator()(const vector<int>& a, const vector<int>& b)const
    {
        if(a[0]==b[0])
        {
            if(a[1]==b[1])
                return a[2] < b[2];
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& inc, vector<vector<int>>& req) {
        int t = 0, n = req.size(), a = 0, b = 0, c =0;
        vector<int> ans(n,-1);
        multimap<vector<int>, int, cmp1> m;
        for(int i = 0; i < n; ++i)
            m.insert(make_pair(req[i],i));

        vector<int> tp;
        auto end1 = m.upper_bound({a,b,c});
        for(auto it = m.begin(); it != end1; )
        {
            tp = it->first;
            if(a>=tp[0] && b>=tp[1] && c>=tp[2])
            { 
                ans[it->second] = t;
                m.erase(it++);//这样做迭代器不会失效
            }
            else
                it++;
        }
        for(int i = 0; i < inc.size(); ++i)
        {
            t = i+1;
            a += inc[i][0];
            b += inc[i][1];
            c += inc[i][2];
            auto end = m.upper_bound({a,b,c});
            for(auto it = m.begin(); it != end; )
            {
                tp = it->first;
                if(a>=tp[0] && b>=tp[1] && c>=tp[2])
                {
                    ans[it->second] = t;
                    m.erase(it++);//这样做迭代器不会失效
                }
                else
                    it++;
            }
        }
        return ans;
    }
};