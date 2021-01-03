class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long count = 0, n = S.size(), i = 0;
        for( ; i < n; ++i)
        {
            if(isalpha(S[i]))
                count++;
            else
                count *= S[i]-'0';
            if(count >= K)
                break;
        }
        for( ; i >= 0; --i)
        {
            K = K%count;
            if(K==0 && isalpha(S[i]))
                return string(1, S[i]);
            if(isalpha(S[i]))
                count--;
            else
                count /= S[i]-'0';
        }
        return "";
    }
};
