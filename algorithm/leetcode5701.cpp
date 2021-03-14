class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int count = 0;
        vector<char> d1, d2;
        for(int i = 0; i < s1.size(); ++i)
        {
            if(s1[i] != s2[i])
            {
                count++;
                if(count > 2)
                    return false;
                d1.push_back(s1[i]);
                d2.push_back(s2[i]);
            }
        }
        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());
        return count==0 || (count==2 && d1==d2);
    }
};