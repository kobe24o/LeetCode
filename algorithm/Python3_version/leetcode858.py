class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        def gcd(a, b):
            while a:
                r = a%b
                a = b
                b = r
            return b
            
        g = gcd(q, p); # 最大公约数
        m = p*q/g; #最小公倍数，向上走的距离
        if (m/p)%2 == 0:
            return 0
        if (m/q)%2 == 1:
            return 1
        return 2