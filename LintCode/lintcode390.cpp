class Solution {
public:
    vector<int> findPeakII(vector<vector<int>> &A) {
        int n = A.size(), m = A[0].size();
        int i = 1, j = 1;//从(1,1)开始，（0,0）不可能是答案
        vector<int> ans;
        for( ; 1 ; ++i)
        {
        	//找中间点
            while(A[i][j] < A[i][j+1])
                j++;
            while(A[i][j] < A[i][j - 1])
                j--;
            //判断上下是否也满足
            if(A[i][j] > A[i + 1][j] && A[i][j] > A[i - 1][j])
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
        return {-1,-1};
    }
};