class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> m;
        for(auto& p : pieces)
            m[p[0]] = p;
        int i = 0, j = 0;
        for( ; i < arr.size(); )
        {
            int first = arr[i];
            if(m.find(first) == m.end())
                return false;
            for(j = 0; j < m[first].size(); ++j)
            {
                if(arr[i++] != m[first][j])
                    return false;
            }
        }
        return true;
    }
};