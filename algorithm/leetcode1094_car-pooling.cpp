class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    	int s[1001] = {0}, i;
        for(i = 0; i < trips.size(); ++i)
        {
        	s[trips[i][1]] += trips[i][0];
        	s[trips[i][2]] += -trips[i][0];
        }
        if(s[0] > capacity)
        	return false;
        for(i = 1; i <= 1000; ++i)
        {
        	s[i] += s[i-1];
        	if(s[i] > capacity)
        		return false;
        }
        return true;
    }
};