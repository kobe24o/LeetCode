class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> degree(n);
        for(auto& e : edges) {
            if(++degree[e[0]-1] > 1)
                return e[0];
            if(++degree[e[1]-1] > 1)
                return e[1];
        }
        return -1;
    }
};