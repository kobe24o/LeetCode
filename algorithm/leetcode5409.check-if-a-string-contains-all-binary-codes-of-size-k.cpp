class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() <= k)
            return false;
        int i, l = 0, r = 0, num;
        set<int> st;
        for( ; r < s.size(); ++r)
        {
            if(r-l+1 == k)
            {
                num = 0;
                for(i = l; i <= r; ++i)
                    num = s[i]-'0' + (num<<1);
                st.insert(num);
                l++;
            }
        }
        return st.size()== (1<<k);
    }
};

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() <= k)
            return false;
        int i, l = 0, r = 0;
        set<int> st;
        string str;
        for( ; r < s.size(); ++r)
        {
            if(r-l+1 == k)
            {
                str = s.substr(l,k);
                st.insert(stoi(str,0,2));
                l++;
            }
        }
        return st.size()== (1<<k);
    }
};