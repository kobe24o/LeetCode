class Solution {
public:
    string reorderSpaces(string text) {
        int space = 0, word = 0, n = text.length();
        vector<string> w;
        string s;
        for(int i = 0; i < n; i++) 
        {
            if(text[i] == ' ')
                space++;
            else
            {
                s += text[i];
                if((i < n-1 && text[i+1] == ' ') || i == n-1)
                {
                    word++;
                    w.push_back(s);
                    s = "";
                }
            }
        }
        if(word == 1)
            return w[0]+string(space, ' ');
        int len = space/(word-1);
        int rest = space - len*(word-1);
        string ans;
        string empty(len,' ');
        for(int i = 0; i < w.size(); i++)
        {
            ans += w[i];
            if(i < w.size()-1)
                ans += empty;
        }
        return ans+string(rest, ' ');
    }
};