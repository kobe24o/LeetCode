class MyCalendar {
    set<pair<int, int>> s;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        if(s.empty())
        {
            s.insert({start, end});
            return true;
        }
        auto it = s.lower_bound({start,end});
        if(it == s.end())
        {
            auto it1 = it;
            it1--;//检查前面是否相交
            if(it1->second > start)
                return false;
        }
        else if(it == s.begin())
        {
            if(it->first < end)//检查当前是否相交
                return false;
        }
        else//前后都要检查
        {
            if(it->first < end)
                return false;
            it--;
            if(it->second > start)
                return false;
        }
        s.insert({start, end});
        return true;    
    }
};

class MyCalendar {
    set<pair<int, int>> s;
public:
    MyCalendar() {
        s.insert({INT_MAX, INT_MAX});
        s.insert({INT_MIN, INT_MIN});//加入边界，简化代码
    }
    
    bool book(int start, int end) {
        auto it = s.lower_bound({start,end});
        if(it->first < end)//当前是否相交
            return false;
        if((--it)->second > start)//前面是否相交
            return false;
        s.insert({start, end});
        return true;    
    }
};