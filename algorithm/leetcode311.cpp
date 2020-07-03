class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans(A.size(), vector<int>(B[0].size(), 0));
        int i, j, k, sum;
        for(i = 0; i < A.size(); ++i)
        	for(j = 0; j < B[0].size(); ++j)
        	{
        		sum = 0;
        		for(k = 0; k < A[0].size(); ++k)
        			sum += A[i][k]*B[k][j];
        		ans[i][j] = sum;
        	}
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<bool> r_all0(A.size(),true);
        vector<bool> c_all0(B[0].size(),true);
        int i, j, k, sum;
        bool flag = false;
        for(i = 0; i < A.size(); ++i)
        {
            flag = false;
            for(j = 0; j < A[0].size(); ++j)
            {
                if(A[i][j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                r_all0[i] = false;
        }
        for(j = 0; j < B[0].size(); ++j)
        {
            flag = false;
            for(i = 0; i < B.size(); ++i)
            {
                if(B[i][j])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                c_all0[j] = false;
        }
        vector<vector<int>> ans(A.size(), vector<int>(B[0].size(), 0));
        for(i = 0; i < A.size(); ++i)
        	for(j = 0; j < B[0].size(); ++j)
        	{
                if(r_all0[i] || c_all0[j])
                    continue;
        		sum = 0;
        		for(k = 0; k < A[0].size(); ++k)
        			sum += A[i][k]*B[k][j];
        		ans[i][j] = sum;
        	}
        return ans;
    }
};