class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = __gcd(p, q);//最大公约数
        int m = p*q/g;//最小公倍数，向上走的距离
        if((m/p)%2 == 0)
        	return 0;
        if((m/q)%2 == 1)
        	return 1;
        return 2;
    }
};