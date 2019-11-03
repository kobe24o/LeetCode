class Solution {
public:
    int reachNumber(int target) {
        int i = 1;
        target = abs(target);
        int x = (i*i+i)/2-target;
        while(x < 0 || x%2 == 1)
        {
        	++i;
        	x = (i*i+i)/2-target;
        }
        return i;
    }
};