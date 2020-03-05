class Solution {
public:
    vector<int> swapNumbers(vector<int>& n) {
        n[0] ^= n[1] ^= n[0] ^= n[1];
        return n;
    }
};