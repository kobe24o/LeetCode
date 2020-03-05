class Solution {
public:
    int add(int a, int b) {
        int sum;
        while(b)
        {
            sum = a^b;
            b = (unsigned(a&b))<<1;
            a = sum;
        }
        return a;
    }
};