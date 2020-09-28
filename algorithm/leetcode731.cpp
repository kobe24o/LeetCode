class MyCalendarTwo {
    set<pair<int, int>> s;//区间
    set<pair<int, int>> intersection;//区间交集
public:
    MyCalendarTwo() {
        s.insert({INT_MAX, INT_MAX});
        s.insert({INT_MIN, INT_MIN});//加入边界，简化代码
        intersection.insert({INT_MAX, INT_MAX});
        intersection.insert({INT_MIN, INT_MIN});//加入边界，简化代码
    }
    
    bool book(int start, int end) {
        auto it = intersection.lower_bound({start,end});
        if(it->first < end)//当前跟交集是否相交
            return false;
        if((--it)->second > start)//前面跟交集是否相交
            return false;
        auto it1 = s.lower_bound({start,end});
        auto it2 = it1;
        while(it2 != s.end() && it2->first < end)//当前跟区间是否相交
        {
            intersection.insert({it2->first, min(it2->second, end)});
            it2++;
        }
        it2 = it1;
        while(it2 != s.begin() && (--it2)->second > start)//前面跟区间是否相交
        {
            intersection.insert({max(it2->first, start), it2->second});
            it2--;
        }
        s.insert({start, end});
        return true;    
    }
};