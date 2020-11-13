class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size(), MAX = INT_MIN, MIN = INT_MAX;
        vector<int> left_max(n), right_min(n);
        for(int i = 0; i < n; i++) 
        {
            MAX = max(MAX, A[i]);
            left_max[i] = MAX;
        }
        for(int i = n-1; i >= 0; i--) 
        {
            MIN = min(MIN, A[i]);
            right_min[i] = MIN;
        }
        for(int i = 0; i < n-1; i++)
        {
            if(left_max[i] <= right_min[i+1])
                return i+1;
        }
        return -1;
    }
};