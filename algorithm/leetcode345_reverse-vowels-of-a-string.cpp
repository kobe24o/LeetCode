class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        char l, r;
        while(i < j)
        {
        	l = tolower(s[i]);
        	if(l != 'a' && l != 'e' && l != 'i' && l != 'o' && l != 'u')
        	{
        		i++;
        		continue;
        	}
        	r = tolower(s[j]);
        	if(r != 'a' && r != 'e' && r != 'i' && r != 'o' && r != 'u')
        	{
        		j--;
        		continue;
        	}
        	swap(s[i],s[j]);
        	i++;
        	j--;
        }
        return s;
    }
};