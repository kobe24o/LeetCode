class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() < 2)
        	return false;
        map<int, int> m;
        for(int n : deck)
        	m[n]++;
        if(m.size() == 1)
        	return m.begin()->second%2 == 0;
        int a = m.begin()->second, g;
        map<int, int>::iterator it = ++m.begin();
        for( ; it != m.end(); ++it)
        {
        	g = gcd(a,it->second);
        	a = g;
        }
        if(g == 1)
        	return false;
        return true;
    }

    int gcd(int a, int b)
    {
    	int r;
    	while(b != 0)
    	{
    		r= a%b;
    		a = b;
    		b= r;
    	}
    	return a;
    }
};