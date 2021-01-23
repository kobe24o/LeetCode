class SummaryRanges {
    map<int,int> m; // start, end
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }
    
    void addNum(int val) {
        if(m.empty()){
            m[val] = val;
            return;
        }
        auto it = m.lower_bound(val); // it 的 start >= val
        if(it != m.end()) // 后面有区间
        {
            int start = it->first;
            int end = it->second;
            if(start == val)
                return;
            else if(start == val+1) // val 可以 跟 it 区间合并
            {
                if(it != m.begin()) // it 前面还有区间
                {
                    it--;
                    int prevStart = it->first;
                    int prevEnd = it->second;
                    if(prevEnd+1 == val) // val 可以跟前面合并
                    {
                        m.erase(start);//删除后面区间
                        m[prevStart] = end;//两个区间合并
                    }
                    else//不能跟前面合并
                    {
                        m.erase(start);
                        m[val] = end;//更新后面的区间
                    }
                }
                else//前面没有区间
                {
                    m.erase(start);
                    m[val] = end;//更新后面的区间
                }
            }
            else // val 不可以 跟 it 区间合并
            {
                if(it != m.begin()) // it 前面还有区间
                {
                    it--;
                    int prevStart = it->first;
                    int prevEnd = it->second;
                    if(prevEnd+1 == val)
                    {   // val 可以跟前面合并
                        m[prevStart] = val;
                    }
                    else if(prevEnd+1 < val)
                    {   // 前后都不能合并，自己独立
                        m[val] = val;
                    }
                }
                else
                {
                    m[val] = val;
                }
            }
        }
        else // 后面没有区间
        {
            it--;
            int prevStart = it->first;
            int prevEnd = it->second;
            if(prevEnd+1 == val)
            {   // 可以跟前面合并
                m[prevStart] = val;
            }
            else if(prevEnd+1 < val)
                m[val] = val;//不能合并，独立
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans(m.size());
        int i = 0;
        for(auto& mi : m)
        {
            ans[i++] = {mi.first, mi.second};
        }
        return ans;
    }
};