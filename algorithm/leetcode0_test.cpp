/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),[](vector<int>& a, vector<int>& b)
        		{
        			if(a[0] == b[0])
        				return a[1] < b[1];
        			return a[0] < b[0];
        		});
        int i, j, count = 0, attendTime = 0;
        for(i = 0; i < events.size(); ++i)
        {
        	if(attendTime < events[i][0])
        	{
        		attendTime = events[i][0];
        		count++;
        		attendTime++;
        	}
        	else if(attendTime <= events[i][1])
        	{
        		for(j = i+1; j < events.size() && events[i][1] <= events[j][1]; ++j)
        			;
        		if(j < events.size() && attendTime >= events[j][0])
        		{
        			count++;
        			events.erase(events.begin()+j);
        			attendTime++;
        			i--;
        			continue;
        		}
                count++;
        		attendTime++;
        	}
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1,1},{1,2},{3,3},{1,5},{1,5}};
    sort(v.rbegin(),v.rend());
    cout << s.maxEvents(v);
}