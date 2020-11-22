class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        while(n)
        {
            if(n == 1)
            {   //最后一个字符
                ans += char('a'+k-1);
                break;
            }  
            if(ceil((k-1)/double(n-1))<=26)
            {   //每次尽量以a开头，前提，剩余的分配数字不可以超过26
                ans += "a";
                k -= 1;
            }
            else
            {   //剩余的会超26，当前的取多出来的
                int id = k-(n-1)*26;
                ans += char('a'+id-1);
                k -= id;
            }
            n--;
        }
        return ans;
    }
};