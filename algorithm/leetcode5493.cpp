class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), i, j, l = -1, r = -1;
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
        int ans = min(n-l-1, r);//删除右侧的、或者删除左侧的
        i = 0, j = r;
        while(i <= l && j < n)
        {
            if(arr[i] <= arr[j])
            {
                ans = min(ans, j-i-1);
                i++;
            }
            else
                j++;
        }
        return ans;
    }
};