class MyCalendarTwo {
    set<pair<int, int>> s;//区间
    set<pair<int, int>> intersection;//区间交集
public:
    MyCalendarTwo() {
        intersection.insert({INT_MAX, INT_MAX});
        intersection.insert({INT_MIN, INT_MIN});//加入边界，简化代码
    }
    
    bool book(int start, int end) {
        auto it = intersection.lower_bound({start,end});
        if(it->first < end)//当前跟交集是否相交
            return false;
        if((--it)->second > start)//前面跟交集是否相交
            return false;
        for(auto it1 = s.begin(); it1 != s.end(); it1++)//当前跟区间是否相交
        {
            if(it1->first < end && it1->second > start)
                intersection.insert({max(it1->first, start), min(it1->second, end)});
        }
        s.insert({start, end});
        return true;    
    }
};

class MyCalendarTwo {
    map<int,int> m;
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int count = 0;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            count += it->second;
            if(count >= 3)
            {
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};