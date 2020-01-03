class Solution {
    string p, q, sum;
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        if(S.size() < 3)
            return ans;
        int i, j;
        for(i = 0; i < S.size()/2; ++i)
            for(j = i+1; j < S.size()-1; ++j)
            {
                ans.clear();
                if(isok(S,ans,i,j))
                    return ans;
            }
        return {};
    }

    bool isok(string& S, vector<int>& ans, int i, int j)
    {
        p = S.substr(0,i+1);
        q = sum = "";
        if(p.size()!=1 && p[0]=='0')
            return false;
        bool flag = true;
        ans.push_back(toNum(p,flag));
        if(!flag)//超过int范围
                return false;
        while(j < S.size())
        {
            sum = "";
            q = S.substr(i+1,j-i);
            if(q.size()!=1 && q[0]=='0')
                return false;
            add(p,q);//字符串数字 加法
            if(j+sum.size() >= S.size() || sum != S.substr(j+1,sum.size()))
                return false;
            p = q;
            i = j;
            j += sum.size();
            ans.push_back(toNum(p,flag));
            if(!flag)
                return false;
            if(j == S.size()-1)
            {
                ans.push_back(toNum(sum,flag));
                if(!flag)
                    return false;
                break;
            }
        }
        return true;
    }

    void add(string& a, string& b)
    {
        int i = a.size()-1, j = b.size()-1, carry = 0, bit, s;
        while(i >= 0 || j >= 0 || carry)
        {
            s = carry+ (i>=0 ? a[i--]-'0' : 0) + (j>=0 ? b[j--]-'0' : 0);
            bit = s%10;
            carry = s/10;
            sum.insert(0,1,bit+'0');
        }
    }

    int toNum(string& s, bool& flag)
    {
        long n = 0;
        for(int i = 0; i < s.size(); i++)
        {
            n = n*10+(s[i]-'0');
            if(n > INT_MAX)
            {   
                flag = false;
                return -1;
            }
        }
        return int(n);
    }
};