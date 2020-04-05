class Solution {
public:
    int numSteps(string s) {
    	int count = 0;
    	while(s != "1")
    	{
    		if(s.back()=='0')
    			s.pop_back();//右移除以2
    		else
    			addone(s);
    		count++;
    	}
    	return count;
    }

    void addone(string &s)
    {
    	int i = s.size()-1, carry = 1;
    	while(i >= 0 && carry)
    	{
    		if(s[i]=='0')
    		{
    			s[i] = '1';
    			carry = 0;
    		}
    		else
    		{
    			s[i] = '0';
    			carry = 1;
    		}
            i--;
    	}
    	if(carry)
    		s.insert(0,"1");
    }
};