class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        string cur, nt, minstr = s;
        int i, n = s.size(), bit;
        vis.insert(s);
        queue<string> q;
        q.push(s);
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            if(cur < minstr)
                minstr = cur;
            nt = cur;
            for(i = 1; i < n; i+=2)
            {
                bit = (cur[i]-'0'+a)%10;
                nt[i] = bit+'0';
            }
            if(!vis.count(nt))
            {
                vis.insert(nt);
                q.push(nt);
            }
            nt = cur.substr(n-b)+cur.substr(0,n-b);
            if(!vis.count(nt))
            {
                vis.insert(nt);
                q.push(nt);
            }
        }
        return minstr;
    }
};