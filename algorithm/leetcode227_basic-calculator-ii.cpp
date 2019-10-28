class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char op = '+';
        int prev = 0, num = 0, ans = 0;
        for(int i = 0; i < s.size(); i++) 
        {
            if(isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            if(s[i] < '0' && s[i] != ' ' || i == s.size()-1)
            {
                if(op == '+')
                    stk.push(num);
                else if(op == '-')
                    stk.push(-num);
                else if(op == '*')
                {
                    prev = stk.top();
                    stk.pop();
                    stk.push(prev*num);
                }
                else
                {
                    prev = stk.top();
                    stk.pop();
                    stk.push(prev/num);
                }
                op = s[i];
                num = 0;
            }
        }
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.calculate("3+2*2");
}