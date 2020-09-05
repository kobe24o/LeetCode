class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), i, l = -1, r = -1;
        if(n == 1) return 0;
        for(i = 1; i < n; ++i) 
        {
            if(arr[i-1] > arr[i])
            {
                l = i-1;
                break;
            }
        }
        if(l == -1)
            return 0;
        for(i = n-2; i >= 0; --i)
        {
            if(arr[i] > arr[i+1])
            {
                r = i+1;
                break;
            }
        }
        int L = l, R = r;
        while(l>=0 && r < n)
        {
            if(arr[l] > arr[r])
                l--;
            else
                break;
        }
        int ans = r-l-1;
        l = L, r = R;
        while(l>=0 && r < n)
        {
            if(arr[l] > arr[r])
                r++;
            else
                break;
        }
        return min(ans, r-l-1);
    }
};