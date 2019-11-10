class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
    	int n = costs.size();
        vector<pair<int,int>> v(n);
        int i, money = 0;
        for(i = 0; i < n; ++i)
        {
        	v[i].first = costs[i][0]-costs[i][1];
        	v[i].second = i;
        }
        sort(v.begin(),v.end(),[](auto &a, auto &b)
        						{return a.first < b.first;});
        for(i = 0; i < n/2; ++i)
        	money += costs[v[i].second][0];
        for(i = n/2; i < n; ++i)
        	money += costs[v[i].second][1];
        return money;
    }
};