class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    	int sum = 0, i = 0, j = 0, n = calories.size(), points = 0;
    	while(j < k-1)
    		sum += calories[j++];
    	while(j < n)
    	{
    		sum += calories[j++];
    		if(sum < lower)
    			points--;
    		else if(sum > upper)
    			points++;
    		sum -= calories[i++];
    	}
    	return points;
    }
};