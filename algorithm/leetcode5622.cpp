class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long curtime = customers[0][0], arrivetime, waittimes = 0, n = customers.size();
        for(int i = 0; i < n; i++) 
        {
            arrivetime = customers[i][0];//到达时间
            int needtime = customers[i][1];//做菜时间
            curtime = max(curtime, arrivetime);//max，比如到达时间晚于当前时间
            curtime += needtime;//做菜去了
            waittimes += curtime - arrivetime;//等待时间
        }
        return waittimes/double(n);
    }
};