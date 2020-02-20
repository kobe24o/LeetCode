class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(n == s.size())
        	return s;
        int i = 0, count = n, size = s.size();
        while(count--)
        	s.push_back(s[i++]);
        return s.substr(n,size);
    }
};

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n,s.size()-n)+s.substr(0,n);
    }
};