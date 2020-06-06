class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        Q = 0
        W = 0
        E = 0
        R = 0
        nt = n>>2
        for i in range(n):
            if s[i] == 'Q':
                Q += 1
            elif s[i] == 'W':
                W += 1
            elif s[i] == 'E':
                E += 1
            else:
                R += 1
        if Q==nt and W==nt and E==nt and R==nt:
            return 0;
        i = 0
        minlen = n
        for j in range(n):
            if Q > nt or W > nt or E > nt or R > nt:
            # 窗口外多了，进入窗口一个，窗口外少了，计数-1
                if s[j] == 'Q':
                    Q -= 1
                elif s[j] == 'W':
                    W -= 1
                elif s[j] == 'E':
                    E -= 1
                else:
                    R -= 1
            while i < n and (Q <= nt and W <= nt and E <= nt and R <= nt):
            # 窗口外满足条件，我要尽可能的让窗口小，让左端点出去，窗口外计数+1
                minlen = min(minlen, j-i+1)
                if s[i] == 'Q':
                    Q += 1;
                elif s[i] == 'W':
                    W += 1
                elif s[i] == 'E':
                    E += 1
                else:
                    R += 1;
                i += 1;
        return minlen