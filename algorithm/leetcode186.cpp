class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s, 0, s.size()-1);
        int l = 0, r;
        while(r < s.size())
        {
        	while(r < s.size() && s[r]!=' ')//没遇见分隔符
        		r++;
        	reverse(s, l, r-1);
        	r++;//跳过空格
        	l = r;
        }
    }
    void reverse(vector<char>& s, int l, int r)
    {
    	while(l < r)
    		swap(s[l++],s[r--]);
    }
};