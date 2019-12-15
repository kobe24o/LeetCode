class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())
            return "0";
        char m;
        int len = num.size()-k, i;//目标长度len
        string s;
        for(i = 0; i < num.size(); ++i)
        {
        	m = num[i];
        	while(!s.empty() && s.back() > m && k)
        	{
        		s.pop_back();
        		k--;
        	}
        	if(k == 0)
        		break;
        	s.push_back(m);
        }
        if(k == 0)
        	s = s + num.substr(i); 
        while(s.size() != len)//删的次数不够，说明是顺序的，提前跑到末尾了
        	s.pop_back();//末尾数字大，删除
        while(s.size()>1 && s[0]=='0')//去除前置0
        	s.erase(0,1);
        return s;
    }
};
