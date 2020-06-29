class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int i = 0, l = 0, r = 0;
        for(i = 1; i < A.size(); ++i)
        {
            if(A[i-1] > A[i])//遇到下降
                l = i-1, r = i;
            //后序找到小于 A[i-1] 的数
            else if(A[i] < A[l] && A[i] > A[r])
                r = i;
        }
        swap(A[l], A[r]);
        return A;
    }
};