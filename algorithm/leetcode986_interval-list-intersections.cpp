class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty() || B.empty())
            return {};
        int i = 0, j = 0, left, right;
        vector<vector<int>> ans;
        vector<int> temp;
        while(i < A.size() && j < B.size())
        {
            left = max(A[i][0], B[j][0]);
            right = min(A[i][1], B[j][1]);
            temp.push_back(left);
            temp.push_back(right);
            if(A[i][0] > B[j][0])
            {
                if(A[i][1] <= B[j][1])//case 4
                    ++i;
                else
                    ++j;
                if(left <= right)
                    ans.push_back(temp);
            }
            else if(A[i][0] < B[j][0])
            {
                if(A[i][1] >= B[j][1])//case 1 && 7
                    ++j;
                else//case 3
                    ++i;
                if(left <= right)
                    ans.push_back(temp);
            }
            else//A[i][0] == B[j][0]
            {
                if(A[i][1] < B[j][1])
                    ++i;
                else if(A[i][1] > B[j][1])
                    ++j;
                else
                    ++i, ++j;
                ans.push_back(temp);
            }
            temp.clear();
        }
        return ans;
    }
};