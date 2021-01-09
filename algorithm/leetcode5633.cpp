class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, L = n/7;
        int week = 1+2+3+4+5+6+7;
        ans += L*(week+(week+(L-1)*7))/2;
        int num = L+1, i = L*7+1;
        while(i <= n)
            ans += num++, 
            i++;
        return ans;
    }
};