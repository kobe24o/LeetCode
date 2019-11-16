class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string origin(to_string(N));
        string powerTwo;
        int k=1;
        sort(origin.begin(), origin.end());
        for(int i = 0; i < 32; ++i)
        {
        	powerTwo = to_string(k<<i);
        	sort(powerTwo.begin(), powerTwo.end());
        	if(powerTwo == origin)
        		return true;
        }
        return false;
    }
};

class Solution {
	bool ans = false;
public:
    bool reorderedPowerOf2(int N) {
        string origin(to_string(N));
        bt(origin,0);
        return ans;
    }

    void bt(string str, int i)
    {
    	if(ans == true || i == str.size())
    		return;
    	for(int j = i; j < str.size(); ++j)
    	{
    		swap(str[i],str[j]);
    		if(str[0]!='0' && isPowerTwo(stoi(str)))
    			ans = true;
    		bt(str,i+1);
    		swap(str[i],str[j]);
    	}
    }

    bool isPowerTwo(int n)
    {
    	return (n&(n-1)) == 0;
    }
};