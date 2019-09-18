class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0, bit;
        while(n > 0)
        {
            bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do
        {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }
        while(slow != fast);
        return slow == 1;
    }
};