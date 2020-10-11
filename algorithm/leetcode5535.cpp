class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0, deep = 0;
        for(char c : s)
        {
            if(c == '(')
                deep++;
            else if(c == ')')
                deep--;
            maxdepth = max(maxdepth, deep);
        }
        return maxdepth;
    }
};