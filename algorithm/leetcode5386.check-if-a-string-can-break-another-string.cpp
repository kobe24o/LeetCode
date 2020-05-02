class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool flag = true;
        for(int i = 0; i < s1.size(); ++i)
        {
            flag &= (s1[i]>=s2[i]);
            if(!flag)
                break;
        }
        if(flag)
            return flag;
        flag = true;
        for(int i = 0; i < s1.size(); ++i)
        {
            flag &= (s1[i]<=s2[i]);
            if(!flag)
                break;
        }
        return flag;
    }
};