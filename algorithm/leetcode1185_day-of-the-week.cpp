class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string week[7] = {"Thursday", "Friday", "Saturday","Sunday","Monday", "Tuesday", "Wednesday"};
        int i, days = 0, monthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        //1971-1-1 周五
        for(i = 1971; i < year; ++i)
        {
        	if((i%4 == 0 && i%100 != 0) || i%400 == 0)
        		days += 366;
        	else
        		days += 365;
        }
        for(i = 0; i < month-1; ++i)
        {
        	days += monthdays[i];
        }
        days += day;
        if(((year%4 == 0 && year%100 != 0) || year%400 == 0) && month > 2)
        	++days;
        return week[days%7];
    }
};