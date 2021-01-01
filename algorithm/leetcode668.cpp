class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n, mid, ans;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            if(ok(m,n,mid,k))
            {   //选取数字为mid时，有 >= k 个数 <= mid
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
    bool ok(int m, int n, int mid, int k) 
    {   // 检查每一行，<= mid 的数，共计有多少个
        int count = 0;
        for(int i = 1; i <= m; i++)
        {
            count += min(mid/i, n);//每行最多有n个数小于 mid
        }
        return count >= k;//有count 个数 <= mid
    }
};