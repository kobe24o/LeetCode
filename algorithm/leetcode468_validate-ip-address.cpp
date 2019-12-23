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
        string p;
        for(int i = 0; i < IP.size(); ++i)
        {
            if((IP[i]==ch || i == IP.size()-1))
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

    bool isIPv4(string &IP)
    {
        char ch = '.';
        vector<string> part;
        split(IP, ch, part);
        if(part.size() != 4)    //长度不为4，错误
            return false;
        int s, i;
        for(auto p : part)
        {
            s = 0;
            if(p == "" || (p[0] == '0' && p.size() != 1))   //不能有前置0
                return false;
            for(i = 0; i < p.size(); ++i)
            {
                if(!isdigit(p[i]))
                    return false;
                s = s*10+p[i]-'0';
                if(s > 255) //数字不能超范围
                    return false;
            }
        }
        return true;
    }

    bool isIPv6(string &IP)
    {
        char ch = ':';
        vector<string> part;
        split(IP, ch, part);
        if(part.size() != 8)    //长度为8才行
            return false;
        int i;
        for(auto p : part)
        {
            if(p.size() == 0 || p.size() > 4)//长度1-4才行
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