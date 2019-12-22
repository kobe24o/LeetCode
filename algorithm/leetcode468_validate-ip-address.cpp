class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.find('.') != string::npos && isIPv4(IP))
        	return "IPv4";
        if(IP.find(':') != string::npos && isIPv6(IP))
        	return "IPv6";
        return "Neither";
    }

    void split(string &IP, char &ch, vector<string> &part)
    {
    	int k = 1;
    	string p;
    	for(int i = 0; i < IP.size(); ++i)
    	{
    		if((IP[i]==ch || i == IP.size()-1))
    		{
    			part.push_back(p);
    			p = "";
    		}
    		else
    			p += IP[i];
    	}
    }

    bool isIPv4(string &IP)
    {
    	char ch = '.';
    	vector<string> part;
    	split(IP, ch, part);
    	int s, i;
    	for(auto p : part)
    	{
    		s = 0;
    		if(p == "" || (p[0] == '0' && p.size() != 1))
    			return false;
    		for(i = 0; i < p.size(); ++i)
    		{
    			if(!isdigit(p[i]))
    				return false;
    			s = s*10+p[i]-'0';
    		}
    		if(!(s>= 0 && s <= 255))
    			return false;
    	}
    	return true;
    }

    bool isIPv6(string &IP)
    {
    	char ch = ':';
    	vector<string> part;
    	split(IP, ch, part);
    	int i;
    	for(auto p : part)
    	{
    		if(p.size() > 4)
    			return false;
    		for(i = 0; i < p.size(); ++i)
    		{
    			if(!(isdigit(p[i]) || (tolower(p[i])>='a' && tolower(p[i])<='f') )) 
    				return false;
    		}
    	}
    	return true;
    }
};