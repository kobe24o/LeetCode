class Solution {
public:
    int hammingDistance(int x, int y) {
        int sum = x^y;//异或
        int count = 0;
        while(sum)
        {
            sum &= (sum-1);
            ++count;
        }
        return count;
    }
};