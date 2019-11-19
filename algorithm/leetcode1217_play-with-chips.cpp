class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int a = 0, b = 0;
        for(int &chip : chips)
        	if(chip%2)
        		a++;
        	else
        		b++;
		return min(a,b);
    }
};