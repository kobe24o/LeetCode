class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> m;//多米诺组成的最小两位数，-->计数
        int num;
        for(auto& d : dominoes)
        {
        	num = d[0]>d[1] ? d[1]*10+d[0] : d[0]*10+d[1];
        	m[num]++;
        }
        num = 0;
        for(auto& mi : m)
        	num += mi.second*(mi.second-1)/2;
        return num;
    }
};