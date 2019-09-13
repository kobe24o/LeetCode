class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start == destination)
        	return 0;
        int Dis1 = 0, Dis2 = 0, i, n = distance.size();
        if(start > destination)
        	swap(start, destination);
        for(i = start; i != destination; i++)
        {
        	Dis1 += distance[i];
        	if(i == n-1)
        		i = -1;
        }
        for(; i != start; i++)
        {
        	Dis2 += distance[i];
        	if(i == n-1)
        		i = -1;
        }
        return min(Dis1, Dis2);
    }
};