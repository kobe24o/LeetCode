class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> diff(n);
        for(int i = 0; i < n; i++) 
        {
            diff[i].first = aliceValues[i]+bobValues[i];
            diff[i].second = i;
        }
        sort(diff.rbegin(), diff.rend());
        int a = 0, b = 0, i = 0, j = n-1;
        bool alice = true;
        while(i < n)
        {
            if(alice)
            {
                a += aliceValues[diff[i].second];
                i++;
                alice = false;
            }
            else
            {
                b += bobValues[diff[i].second];
                i++;
                alice = true;
            }
        }
        if(a > b) return 1;
        else if(a < b) return -1;
        return 0;
    }
};