#include<math.h>
#include<iostream>
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
            return x;
        double left = 1, right = x/2+1, mid;
        while(right-left > 0.00001)
        {
            mid = (left+right)/2;
            if(mid*mid > x)
                right = mid;
            else
                left = mid;
        }
        return floor(right);
    }
};
int main()
{
	Solution s;
	std::cout << s.mySqrt(2147395599) << std::endl;
	return 0;
}