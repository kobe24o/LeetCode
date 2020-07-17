class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
    	long init = iptolong(ip);
    	vector<string> ans;
    	while(n)
    	{
    		int tail0 = tail0count(init);
    		long mask = 0, numofips = 1;
    		while(numofips < n && mask < tail0)
    		{
    			numofips <<= 1;
    			mask++;
    		}
    		if(numofips > n)
    		{
    			numofips >>= 1;
    			mask--;
    		}
    		ans.push_back(iptostr(init, 32-mask));
    		n -= numofips;
    		init += numofips;
    	}
    	return ans;
    }
    long iptolong(string& ip)
    {
    	vector<int> num;
    	long n = 0, i;
    	for(i = 0; i < ip.size(); ++i)
    	{
    		if(ip[i] == '.')
    		{
    			num.push_back(n);
    			n = 0;
    		}
    		else
    		{
    			n = 10*n+ip[i]-'0';
    			if(i == ip.size()-1)
    				num.push_back(n);
    		}
    	}
    	n = 0;
    	for(i = 0; i < 4; ++i)
    		n = n*256+num[i];
    	return n;
    }
    string iptostr(long n, int range)
    {
    	string ip;
    	vector<int> num;
    	while(n)
    	{
    		num.push_back(n%256);
    		n /= 256;
    	}
        while(num.size() < 4)
            num.push_back(0);
    	ip = to_string(num[3])+'.'+to_string(num[2])+'.'
    		+to_string(num[1])+'.'+to_string(num[0])+'/'+to_string(range);
    	return ip;
    }
    int tail0count(long n)
    {
    	int count = 0, i = 0;
        if(n == 0)
            return 0;
    	while(((n>>i)&1)==0)
    	{
    		count++;
    		i++;
    	}
    	return count;
    }
};