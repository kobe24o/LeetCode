class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        // sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        long long ans = 0, mod = 1e9+7;
        for(int stp : staple) 
        {
            if(stp >= x)
                continue;
            int target = x - stp;
            int pos = bs(drinks, target);
            if(pos != -1)
            {
                ans = (ans+pos+1)%mod;
            }
        }
        return ans;
    }
    int bs(vector<int>& arr, int target)
    {
        int l = 0, r = arr.size()-1, n = arr.size(), mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(arr[mid] > target)
            {
                r = mid-1;
            }
            else
            {
                if(mid == n-1 || arr[mid+1] > target)
                    return mid;
                else
                    l = mid+1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        long long ans = 0, mod = 1e9+7;
        int m = staple.size(), n = drinks.size(), i, j;
        i = 0, j = n-1;
        while(i < m && j >= 0)
        {
            if(staple[i]+drinks[j] <= x)
            {
                ans = (ans+j+1)%mod;
                i++;
            }
            else
                j--;
        }
        return ans;
    }
};