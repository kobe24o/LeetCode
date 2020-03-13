class Solution {
public:
    long long playGames(vector<int> &A) {
        // Write your code here
        sort(A.begin(),A.end());
        int n = A.size();
        int MAX = A[n-1];
        long long sum= 0;
        for(int i = 0; i < n-1; ++i)
        {
            A[i] -= MAX;
            sum += A[i];
        }    
        if(sum + MAX <= 0)
            return MAX;
        else
            return ceil((sum+MAX)/double(n-1))+MAX;
    }
};