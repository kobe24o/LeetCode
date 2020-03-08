class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1)
            return informTime[0];
        int i, t = 0, tmax = 0, leader;
        
        for(i = 0; i < n; i++)
        {
            if(informTime[i] == 0)
            {
                t = 0;
                leader = manager[i];
                while(manager[leader] != -1)
                {
                    t += informTime[leader];
                    leader = manager[leader];
                }
                t += informTime[leader];
                if(t > tmax)
                    tmax = t;
            }
        }
        return tmax;
    }
};