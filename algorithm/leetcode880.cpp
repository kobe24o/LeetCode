class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int encode_len = 0, i;
        string encstr, temp;
        K--;
        for(i = 0; i < S.size(); i++) 
        {
            if(isalpha(S[i]))
            {
                encstr += S[i];
                encode_len++;
                if(encode_len == K+1)
                    return string(1,encstr[K]);
            }
            else
            {
                if(encode_len*(S[i]-'0') >= K+1)
                    return string(1,encstr[K%encode_len]);
                else
                {
                    encode_len *= (S[i]-'0');
                    int n = (S[i]-'0')-1;
                    temp = encstr;
                    while(n--)
                        temp += encstr;
                    encstr = temp;
                }
            }
        }
        return "";
    }
};