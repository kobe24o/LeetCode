class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1) return n;
        vector<int> arr(n+1);
        arr[0] = 0;
        arr[1] = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(2*i >= 2 && 2*i <= n)
            {
                arr[2*i] = arr[i];
                ans = max(ans, max(arr[i], arr[2*i]));
            }
            if(2*i+1 >= 2 && 2*i+1 <= n)
            {
                arr[2*i+1] = arr[i]+arr[i+1];
                ans = max(ans, max(arr[i], arr[2*i+1]));
            }
            else
                break;
        }
        return ans;
    }
};