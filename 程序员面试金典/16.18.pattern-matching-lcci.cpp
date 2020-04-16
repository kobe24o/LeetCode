class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if(pattern==value)
            return true;
        else if(pattern=="" && value!="")
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
            if(value=="")
                return true;
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
            la++;
        }
        return false;
    }
    bool onlyAorB(string& val, int a)
    {
        if(val.size()==0 || val.size()%a)
        //有一个代表空串，val为空，另一个也代表空串，则a=b=""
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
                    idxa = idx;
                idx += la;
            }
            else
            {
                if(idxb == -1)
                    idxb = idx;
                idx += lb;
            }
            i++;
        }
        string sa = val.substr(idxa, la);
        string sb = val.substr(idxb, lb);
        int j = 0, delta;
        for(i = 0; i < pat.size(); ++i, j+=delta)
        {
            if(pat[i]=='a')
            {
                delta = la;
                if(val.substr(j,la) != sa)
                    return false;
            }
            else
            {
                delta = lb;
                if(val.substr(j,lb) != sb)
                    return false;
            }
        }
        return true;
    }
};