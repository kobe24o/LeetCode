class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if(value=="" || pattern==value)
            return true;
        else if(pattern=="" || pattern.size() > value.size())
            return false;
        int i, a = 0, b = 0, vlen = value.size();
        for(i = 0; i < pattern.size(); ++i)
        {
            if(pattern[i]=='a')
                a++;
            else
                b++;
        }
        if(a==0 || b==0)
        {
            a = max(a, b);
            return onlyAorB(value, a);
        }
        //a,b均有的情况
        //a，b均可以表示空字符串
        if(onlyAorB(value,a))//b表示空串
            return true;
        if(onlyAorB(value,b))//a表示空串
            return true;
        //a，b均不表示空
        int la=1, lb=1;//a,b代表的长度
        while(la*a < vlen)
        {
            if((vlen-la*a)%b)//不能整除
            {
                la++;
                continue;
            }
            lb = (vlen-la*a)/b;
            if(good(la,lb,pattern,value))
                return true;
        }
        return false;
    }
    bool onlyAorB(string& val, int a)
    {
        if(val.size()%a)
            return false;
        int n = val.size()/a;
        string sub = val.substr(0,n);
        for(int j = n; j < val.size(); j+=n)
        {
            if(val.substr(j,n) != sub)
                return false;
        }
        return true;
    }
    bool good(int la, int lb, string& pat, string& val)
    {
        int idxa = -1, idxb = -1, i = 0, idx = 0;
        while(idxa==-1 || idxb==-1)
        {
            if(pat[i]=='a')
            {
                if(idxa == -1)
                    idxa = idx
                idx += la;
            }
            else
            {
                if(idxb == -1)
                    idxb = idx;
                idx += lb;
            }
        }
    }
};