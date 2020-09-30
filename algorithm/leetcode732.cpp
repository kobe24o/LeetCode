class MyCalendarThree {
    map<int,int> m;
public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        m[start]++;//差分思想
        m[end]--;
        int count = 0, maxCount = 0;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            count += it->second;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
