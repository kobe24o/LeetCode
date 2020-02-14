class Solution {
public:
    bool isUnique(string astr) {
        long long a = 0, b = 0, one = 1,zero = 0;
        for(auto& ch : astr)
        {
            if(ch < 64)
            {
                if((a&(one<<ch)^(one<<ch))!=zero)
                    a ^= (one<<ch);
                else
                    return false;
            }
            else
            {
                if((b&(one<<(ch-64))^(one<<(ch-64)))!=zero)
                    b ^= (one<<(ch-64));
                else
                    return false;
            }
        }
        return true;
    }
};