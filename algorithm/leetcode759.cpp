/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int l = -1;
        vector<Interval> v;
        for(auto& s: schedule) 
        	for(auto& i : s)
        	{
        		v.push_back(i);
        		l = min(l, i.end);
        	}
        sort(v.begin(), v.end(), [&](auto& a, auto& b){
        	if(a.start == b.start)
        		return a.end < b.end;
        	return a.start < b.start;
        });
        vector<Interval> ans;
        for(int i = 0; i < v.size(); ++i)
        {
        	if(l < v[i].start && l != -1)
        		ans.push_back(Interval(l, v[i].start));
        	l = max(l, v[i].end);
        }
        return ans;
    }
};