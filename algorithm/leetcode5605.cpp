class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        for(auto& w : word1)
            a += w;
        for(auto& w : word2)
            b += w;
        return a == b;
    }
};