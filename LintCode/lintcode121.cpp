class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        vector<vector<string>> ans;
        vector<vector<string>> lv;
        vector<string> path;
        int i, j, n = start.size();
        queue<pair<string,vector<string>>> q;
        bool found = false;
        set<string> visited;
        q.push(make_pair(start,vector<string>(1,start)));
        visited.insert(start);
        int size;
        string tp;
        char origin;
        while(!q.empty())
        {
            size = q.size();
            path.clear();
            while(size--)
            {
                tp = q.front().first;
                path = q.front().second;
                q.pop();
                for(i = 0; i < n; ++i)
                {   
                    origin = tp[i];
                    for(j = 1; j <= 25; ++j)
                    {
                        if(tp[i]=='z')
                            tp[i] = 'a'-1;
                        tp[i]++;
                        if(tp == end)
                        {
                            found = true;
                            path.push_back(tp);
                            q.push(make_pair(tp,path));
                            continue;
                        }
                        if(!visited.count(tp) && dict.count(tp))
                        {
                            path.push_back(tp);
                            q.push(make_pair(tp,path));
                            visited.insert(tp);
                            path.pop_back();
                            
                        }
                    }
                    tp[i] = origin;
                }
            }
            if(found)
            {
                while(!q.empty())
                {
                    if(q.front().second.back() == end)
                        ans.push_back(q.front().second);
                    q.pop();
                }
                break;
            }
        }
        sort(ans.begin(),ans.end(),[&](auto a, auto b){
            for(int i = 0; i < a.size(); ++i)
            {
                if(a[i] == b[i])
                    continue;
                return a[i] < b[i];
            }
        });
        return ans;
    }
};