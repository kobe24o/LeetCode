class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        int i = 1, s = 0, n = piles.size()/3;
        while(n--)
        {
            s += piles[i];
            i += 2;
        }
        return s;
    }
};