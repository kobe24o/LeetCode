class Solution {
    string sum, p, q;
public:
    bool isAdditiveNumber(string num) {
        int i, j;
        if(num.size()<3)
            return false;
        for(i = 0; i < num.size()/2; i++) 
        {
            for(j = i+1; j < num.size()-1; j++)
            {
                sum = p = q = "";
                if(isAdd(num,i,j))
                    return true;
            }
        }
        return false;
    }

    bool isAdd(string& num, int i, int j) 
    {
        p = num.substr(0,i+1);
        if(p.size() != 1 && p[0] == '0')
                return false;
        while(j < num.size())
        {
            sum = "";
            q = num.substr(i+1,j-i);
            if(q.size() != 1 && q[0] == '0')
                return false;
            add(p, q);
            if(j+sum.size() >= num.size() || sum != num.substr(j+1,sum.size()))
                return false;
            p = q;
            i = j;
            j += sum.size();
            if(j == num.size()-1)
                break;
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
};