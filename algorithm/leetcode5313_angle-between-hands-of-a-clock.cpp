class Solution {
public:
    double angleClock(int hour, int minutes) {
        double d1 = 0, d2 = 0;
        d2 = minutes*6;
        d1 = (hour%12)*30 + double(d2)/360*30;
        return min(abs(d1-d2),360-abs(d1-d2));
    }
};