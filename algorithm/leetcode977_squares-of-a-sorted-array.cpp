class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i, j;
        for (i = 0; i < A.size() && A[i] < 0; ++i)
        {
            //find the index of nonpositive value
        }
        j = i-1;
        vector<int> ans;
        while(j >= 0 && i < A.size())
        {
            if(A[i] < abs(A[j]))
            {
                ans.push_back(A[i]*A[i]);
                ++i;
            }
            else
            {
                ans.push_back(A[j]*A[j]);
                --j;
            }
        }
        if(j < 0)
        {
            while(i < A.size())
            {
                ans.push_back(A[i]*A[i]);
                ++i;
            }
        }
        else//i到达末尾
        {
            while(j >= 0)
            {
                ans.push_back(A[j]*A[j]);
                --j;
            }
        }
        return ans;
    }
};