class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> start(26, -1);
        int maxlen = -1;
        for(int i = 0; i < s.size(); ++i) 
        {
            int idx = s[i]-'a';
            if(start[idx]== -1)
                start[idx] = i;
            else
                maxlen = max(maxlen, i-start[idx]-1);
        }
        return maxlen;
    }
};