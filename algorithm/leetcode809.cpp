class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        if(S == "") return 0;
        int ans = 0, num = 0;
        vector<char> S_char;//记录连续的单一字符
        vector<int> count;//单一字符个数
        char prev = S[0];
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] != prev)
            {
                S_char.push_back(prev);
                count.push_back(num);
                num = 1;
                prev = S[i];
            }
            else
            {
                num++;
            }
        }
        S_char.push_back(prev);
        count.push_back(num);
        for(auto& w : words)
        {
            if(w == "")
                continue;
            bool flag = true;
            int i = 0;
            num = 0;
            prev = w[0];
            // 对每个单词同样的方法
            for(int j = 0; j < w.size(); j++)
            {
                if(w[j] != prev)
                {
                    if(i == S_char.size() || prev != S_char[i] || count[i] < num
                        || (count[i] != num && count[i]<3))
                    {// 字符跟S不匹配、S的字符数小于num、个数不等且S中的个数小于3
                        flag = false;//不能得到S
                        break;
                    }
                    i++;
                    num = 1;
                    prev = w[j];
                }
                else
                {
                    num++;
                }
            }
            if(i == S_char.size() || prev != S_char[i] || count[i] < num
                        || (count[i] != num && count[i]<3))
                flag = false;
            if(flag && i == S_char.size()-1)
                ans++;
        }
        return ans;
    }
};