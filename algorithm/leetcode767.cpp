struct cmp
{   
    bool operator()(pair<char,int>& a, pair<char,int>& b)
    {
        return a.second < b.second;//数量多的优先
    }
};
class Solution {
public:
    string reorganizeString(string S) {
        int maxcount = 0;
        vector<int> count(26, 0);
        for(char c : S)
        {
            count[c-'a']++;
            maxcount = max(maxcount, count[c-'a']);
        }
        if(maxcount > (S.size()+1)/2)
            return "";
        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> q;
        for(int i = 0; i < 26; ++i)
        {
            if(count[i]>0)
                q.push({'a'+i, count[i]});
        }
        string ans;
        while(q.size() >= 2)
        {
            vector<pair<char,int>> tmp;
            int dis = 2;
            while(dis--)
            {
                auto tp = q.top();
                q.pop();
                char c = tp.first;
                int num = tp.second;
                ans += c;
                num--;
                if(num > 0)
                    tmp.push_back({c, num});
            }
            for(auto& p : tmp)
                q.push(p);
        }
        while(!q.empty())
        {
            if(q.top().second == 1)
            {
                ans += q.top().first;
                q.pop();
            }
            else
                return "";
        }
        return ans;
    }
};


class Solution {
public:
    string reorganizeString(string S) {
        int maxcount = 0;
        vector<int> count(26, 0);
        for(char c : S)
        {
            count[c-'a']++;
            maxcount = max(maxcount, count[c-'a']);
        }
        if(maxcount > (S.size()+1)/2)
            return "";
        vector<pair<char,int>> char_num;
        for(int i = 0; i < 26; i++)
        {
            if(count[i])
                char_num.push_back({'a'+i, count[i]});
        }
        sort(char_num.begin(), char_num.end(),[&](auto& a, auto& b){
            return a.second > b.second;//数量多的优先
        });
        string ans(S.size(), ' ');
        int idx = 0, i = 0;
        while(i < S.size() && char_num[idx].second > 0)
        {
            ans[i] = char_num[idx].first;
            i += 2;
            if(--char_num[idx].second == 0)
                idx++;
        }
        i = 1;
        while(i < S.size() && char_num[idx].second > 0)
        {
            ans[i] = char_num[idx].first;
            i += 2;
            if(--char_num[idx].second == 0)
                idx++;
        }
        return ans;
    }
};