class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x+y)
        	return false;
        int r;
        while(y != 0)//最大公约数x
        {
        	r = x%y;
        	x = y;
        	y = r;
        }
        return (z==0 || z%x == 0);
    }
};