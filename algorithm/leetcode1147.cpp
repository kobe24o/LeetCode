class Solution {
public:
    int longestDecomposition(string text) {
        int i = 0, j = text.size()-1, ans = 0;
        while(i <= j)
        {
            int maxlen = j-i+1;
            for(int len = 1; len <= maxlen; len++)
            {
                if(text.substr(i,len) == text.substr(j-len+1, len))
                {
                    if(len < maxlen)
                        ans += 2;
                    else
                        ans += 1;
                    i += len;
                    j -= len;
                    break;
                }
            }
        }
        return ans;
    }
};