class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int c = 0;
        vector<int> ct1(m, 0), ct2(n,0);
        for(int i = 0; i < m; ++i)
        {
            c = 0;
            for(int j =0 ; j < n; ++j)
            {
                if(mat[i][j]==1)
                    c++;
            }
            ct1[i] = c;
        }
        for(int j = 0; j < n; ++j)
        {
            c = 0;
            for(int i =0 ; i < m; ++i)
            {
                if(mat[i][j]==1)
                    c++;
            }
            ct2[j] = c;
        }
        c = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j =0 ; j < n; ++j)
            {
                if(mat[i][j] && ct1[i]==1 && ct2[j]==1)
                    c++;
            }
        }
        return c;
    }
};