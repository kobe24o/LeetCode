class Solution {
    int kind;
    unordered_set<int> s;
    string ans;
    vector<int> unit = {0, 1, 10, 100, 1000};
public:
    string crackSafe(int n, int k) {
        kind = pow(k, n);//有多少种密码
        string temp(n, '0');//第一种全零的
        temp.reserve(10000);
        s.insert(0);
        dfs(temp, 0, n, k);
        return ans;
    }
    void dfs(string& temp,  int num, int n, int k) 
    {
        if(ans != "")
            return;
        if(s.size() == kind)
        {
            ans = temp;//找到一种答案
            return;
        }
        int newnum;
        for(int i = 0; i < k; i++)
        {
            newnum = num - unit[n]*(temp[temp.size()-n]-'0');
            temp += char('0'+i);
            newnum = newnum*10 + i;
            if(!s.count(newnum))
            {
                s.insert(newnum);
                dfs(temp, newnum, n, k);
                s.erase(newnum);
            }
            temp.pop_back();
        }
    }
};