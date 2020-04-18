class Solution {
public:
    int minCount(vector<int>& coins) {
    	int i, sum = 0;
    	for(i = 0; i < coins.size(); ++i)
    		sum += ceil(coins[i]/2.0);
    	return sum;
    }
};