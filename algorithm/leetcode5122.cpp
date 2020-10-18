class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size(), n1 = n/20, sum = 0;
        sort(arr.begin(), arr.end());
        for(int i = n1; i < n-n1; ++i)
            sum += arr[i];
        return sum/double(n-2*n1);
    }
};