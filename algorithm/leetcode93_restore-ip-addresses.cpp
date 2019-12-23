#include<vector>
#include<string>
using namespace std;
class Solution {
	vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12)
        	return {};
        bt(s,1,0);
        return ans;
    }

    void bt(string &s, int idx, int count)
    {
    	if(count > 3)//3个.才行
    		return;
    	if(count == 3 && isIPv4(s))
    	{
    		ans.push_back(s);
    		return;
    	}
    	for(int i = idx; i < s.size(); ++i)
    	{
    		s.insert(i,".");
    		bt(s,i+2,count+1);
    		s.erase(i,1);
    	}
    }

    bool isIPv4(string &IP)
    {
    	vector<string> part;
    	split(IP, part);
    	int s, i;
    	for(auto p : part)
    	{
    		s = 0;
    		if(p == "" || (p[0] == '0' && p.size() != 1))	//不能有前置0
    			return false;
    		for(i = 0; i < p.size(); ++i)
    		{
    			if(!isdigit(p[i]))
    				return false;
    			s = s*10+p[i]-'0';
    			if(s > 255)	//数字不能超范围
    			    return false;
    		}
    	}
    	return true;
    }

    void split(string &IP, vector<string> &part)
    {
    	string p;
    	for(int i = 0; i < IP.size(); ++i)
    	{
    		if((IP[i]=='.' || i == IP.size()-1))
    		{
    		    if(i == IP.size()-1)
    		        p += IP[i];
    			part.push_back(p);
    			p = "";
    		}
    		else
    			p += IP[i];
    	}
    }
};

int main()
{
	Solution s;
	s.restoreIpAddresses("0000");
}