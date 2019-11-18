class Solution {
	vector<string> ans;
	int count;
public:
    vector<string> readBinaryWatch(int num) {
    	int i, j;
    	for(i = 0; i < 12; ++i)
    	{
    		for(j = 0; j < 60; ++j)
    		{
    			if(count1(i)+count1(j) == num)
    				ans.push_back(to_string(i)+":"
    						+(j<10 ? ("0"+to_string(j)) : to_string(j)));
    		}
    	}
        return ans;
    }

    int count1(int n)
    {
    	count = 0;
    	while(n)
    	{
    		n = n&(n-1);
    		++count;
    	}
    	return count;
    }
};