class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = sqrt(num), mid;
        unsigned long long square;
        while(l <= r)
        {
        	mid = l+((r-l)>>1);
        	square = mid*mid;
        	if(square == num)
        		return true;
        	if(square < num)
        		l = mid+1;
        	else
        		r = mid-1;
        }
        return false;
    }
};