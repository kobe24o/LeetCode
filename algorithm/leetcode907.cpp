class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        vector<int> L(n, -1), R(n, -1);
        stack<int> s;
        for(int i = 0 ; i < n; ++i)
        {
            while(!s.empty() && A[s.top()] > A[i])
                s.pop();
            L[i] = (s.empty() ? 0 : s.top()+1);
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1 ; i >= 0; --i)
        {
            while(!s.empty() && A[s.top()] >= A[i])//两次等号只能取一次 [71,55,82,55]
                s.pop();
            R[i] = (s.empty() ? n-1 : s.top()-1);
            s.push(i);
        }
        int ans = 0, mod = 1e9+7;
        for(int i = 0; i < n; ++i)
        {
            // cout << L[i] << " " << R[i] << endl;
            ans = (ans + 1LL*(i-L[i]+1)*(R[i]-i+1)*A[i]%mod)%mod;
        }
        return ans;
    }
};
