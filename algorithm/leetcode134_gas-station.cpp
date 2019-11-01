class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalOil = 0, curOil = 0, start;
        for(int i = 0; i < gas.size(); ++i)
        {
        	curOil += gas[i]-cost[i];
        	totalOil += gas[i]-cost[i];
        	if(curOil < 0)
        	{
        		start = i+1;
        		curOil = 0;
        	}
        }
        if(totalOil < 0)
        	return -1;
        return start;
    }
};