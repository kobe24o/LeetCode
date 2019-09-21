class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int i, a, b, l, n, o;
        a = b = l = n = o = 0;
        for(int i = 0; i < text.size(); ++i)
        {
        	if(text[i] == 'a')
        		++a;
        	else if(text[i] == 'b')
        		++b;
        	else if(text[i] == 'l')
        		++l;
        	else if(text[i] == 'n')
        		++n;
        	else if(text[i] == 'o')
        		++o;
        }
        return min(a,min(b,min(l/2,min(n,o/2))));
    }
};