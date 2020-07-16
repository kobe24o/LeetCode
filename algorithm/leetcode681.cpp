class Solution {
public:
    string nextClosestTime(string time) {
        set<int> s;
        s.insert(time[0]-'0');
        s.insert(time[1]-'0');
        s.insert(time[3]-'0');
        s.insert(time[4]-'0');
        if(s.size()==1) return time;//数字都一样
        vector<int> num(s.begin(),s.end());
        int i, j, h, m, size = num.size();
        int hour = (time[0]-'0')*10+time[1]-'0';
        int minute = (time[3]-'0')*10+time[4]-'0';
        int minlargeH = 24, minlargeM = 60;
        int minH = 24, minM = 60;
        for(i = 0; i < size; i++)
        {
        	for(j = 0; j < size; j++)
        	{
        		h = m = num[i]*10+num[j];
        		minH = minM = min(minH, h);
        		if(h > hour && h < minlargeH)
        			minlargeH = h;
        		if(m > minute && m < minlargeM)
        			minlargeM = m;
        	}
        }
        if(minlargeM != 60)
        	return time.substr(0,3)+ (minlargeM>=10 ? to_string(minlargeM) : "0"+to_string(minlargeM));
        if(minlargeH != 24)
        	return (minlargeH>=10? to_string(minlargeH) : "0"+to_string(minlargeH)) + ":" + (minM>=10? to_string(minM) : "0"+to_string(minM));
        return (minH>=10? to_string(minH) : "0"+to_string(minH)) + ":" + (minM>=10? to_string(minM): "0"+to_string(minM));
    }
};