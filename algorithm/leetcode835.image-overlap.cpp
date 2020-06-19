class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i,j,x,y,n=A.size(),maxoverlap = 0;
        vector<vector<int>> offset(2*n+1,vector<int>(2*n+1,0));
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                if(A[i][j])
                    for(x = 0; x < n; ++x)
                        for(y = 0; y < n; ++y)
                            if(B[x][y])
                                offset[i-x+n][j-y+n]++;
        for(i = 0; i <= 2*n; ++i)
            for(j = 0; j <= 2*n; ++j)
                maxoverlap = max(maxoverlap, offset[i][j]);
        return maxoverlap;
    }
};

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i,j,n=A.size(),maxoverlap = 0;
        unordered_map<int,int> offset;
        vector<int> A_, B_;
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
            {
                if(A[i][j])
                    A_.push_back((i<<6)+j);
                if(B[i][j])
                    B_.push_back((i<<6)+j);
            }
        for(auto Ai : A_)
            for(auto Bi : B_)
                offset[Ai-Bi]++;
        for(auto off : offset)
            maxoverlap = max(maxoverlap, off.second);
        return maxoverlap;
    }
};