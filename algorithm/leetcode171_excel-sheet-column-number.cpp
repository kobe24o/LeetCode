class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); ++i)
        {
        	sum = sum*26 + (s[i]-'A'+1);
        }
        return sum;
    }
};