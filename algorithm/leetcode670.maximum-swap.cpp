class Solution {
public:
    int maximumSwap(int num) {
    	string s = to_string(num);
    	int i, n = s.size(), maxnum = -1, maxid;
    	vector<int> rightMaxidx(n,-1);
    	for(i = n-1; i >= 0; --i)
    	{
    		if(s[i]-'0' > maxnum)
    		{
    			maxnum = s[i]-'0';
    			maxid = i;
    		}
    		rightMaxidx[i] = maxid;
    	}
    	for(i = 0; i < n; ++i)
    	{
    		if(rightMaxidx[i] == i || s[i] == s[rightMaxidx[i]])
    			continue;
    		swap(s[i],s[rightMaxidx[i]]);
    		break;
    	}
    	return stoi(s);
    }
};