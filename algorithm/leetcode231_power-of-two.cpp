#include<iostream>
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return (n&(n-1)) == 0;//错误写法 n&(n-1) == 0
    }
};

int main()
{
    Solution s;
    std::cout << s.isPowerOfTwo(16) << std::endl;
    int count = 0, num = 8;
    while(num)
    {
        count++;
        num = num&(num-1);
    }
    std::cout << count << std::endl;
}