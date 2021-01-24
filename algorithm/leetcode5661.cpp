class Solution {
public:
    string maximumTime(string time) {
        string ans = time;
        if(time[0] == '?')
        {
            if(time[1]=='?' || time[1] <= '3')
                ans[0] = '2';
            else
                ans[0] = '1';
        }
        if(time[1] == '?')
        {
            if(time[0] == '0' || time[0] == '1')
                ans[1] = '9';
            else if(time[0] == '2'|| time[0] == '?')
                ans[1] = '3';
        }
        if(time[3] == '?')
            ans[3] = '5';
        if(time[4] == '?')
            ans[4] = '9';
        return ans;
    }
};