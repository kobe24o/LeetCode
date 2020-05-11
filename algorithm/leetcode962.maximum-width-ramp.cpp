class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int maxlen = 0, i;
        for(i = 0; i < A.size(); ++i)
        {
        	if(s.empty() || A[s.top()] > A[i])
                s.push(i);
        }
        for(i = A.size()-1; i >= 0; --i)
        {
            while(!s.empty() && A[i] >= A[s.top()])
            {
                maxlen = max(maxlen, i-s.top());
                s.pop();
            }
        }
        return maxlen;
    }
};