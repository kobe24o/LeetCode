class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> delta(n);
        for(int i = 0; i < n; i++) 
        {
            delta[i].first = aliceValues[i]+bobValues[i];//和大的优先
            delta[i].second = i;
        }
        sort(delta.rbegin(), delta.rend());//和大的优先
        int a = 0, b = 0;
        bool alice = true;
        for(int i = 0; i < n; ++i)
        {
            if(alice)
                a += aliceValues[delta[i].second];
            else
                b += bobValues[delta[i].second];
            alice = !alice;
        }
        if(a > b) return 1;
        else if(a < b) return -1;
        return 0;
    }
};