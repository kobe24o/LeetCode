class Solution {
public:
    int paintingPlan(int n, int k) {
        int x, y, ans = 0;
        if(n*n == k) return 1;
        for(x = 0; x <= n; ++x) 
        {
            for(y = 0; y <= n; ++y)
            {
                if((x+y)*n-x*y == k)
                {
                    ans += C(n,x)*C(n,y);
                }
            }
        }
        return ans;
    }
    int C(int n, int x)
    {
        int up = 1, t = x, down = 1;
        while(t--)
        {
            up *= n--;
            down *= x--;
        }
        return up/down;
    }
};