class Solution {
	vector<int> month = {0,31,28,31,30,31,30,31,31,30,31,30,31};
public:
    int daysBetweenDates(string date1, string date2) {
    	if(date1 == date2)
    		return 0;
    	if(date1 > date2)
    		swap(date1, date2);
    	int days = 0, y1, m1, d1, y2, m2, d2, i;
    	y1 = date1[0]*1000+date1[1]*100+date1[2]*10+date1[3];
    	m1 = date1[5]*10+date1[6];
    	d1 = date1[8]*10+date1[9];
    	y2 = date2[0]*1000+date2[1]*100+date2[2]*10+date2[3];
    	m2 = date2[5]*10+date2[6];
    	d2 = date2[8]*10+date2[9];
    	for(i = 1; i < m1; i++)
    		days -= month[1];
    	if(isleapyear(y1) && m1>2)
    		days--;
    	days -= d1;
    	for(i = y1; i < y2; ++i)
    		days += isleapyear(i) ? 366 : 365;
    	for(i = 1; i < m2; i++)
    		days += month[i];
    	if(isleapyear(y2) && m2>2)
    		days++;
    	days += d2;
    	return days;
    }

    bool isleapyear(int& year)
    {
    	if((year%4 == 0 && year%100 != 0) || year%400 == 0)
    		return true;
    	return false;
    }
};