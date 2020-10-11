class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int l = 0, r = a.size()-1;
        while(l < r && a[l] == b[r])
        {
            l++, r--;
        }
        if(ispalind(a.substr(l, r-l+1)) || ispalind(b.substr(l, r-l+1)))
            return true;
        l = 0, r = a.size()-1;
        while(l < r && b[l] == a[r])
        {
            l++, r--;
        }
        if(ispalind(a.substr(l, r-l+1)) || ispalind(b.substr(l, r-l+1)))
            return true;
        return false;
    }
    bool ispalind(string s)
    {
        int l = 0, r = s.size()-1;
        while(l < r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
};