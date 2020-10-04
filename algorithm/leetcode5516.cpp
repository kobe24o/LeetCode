class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, set<string>> m;
        for(int i = 0; i < keyName.size(); i++) 
        {
            m[keyName[i]].insert(keyTime[i]);
        }
        vector<string> ans;
        string name, time;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            name = it->first;
            if(it->second.size() < 3)
                continue;
            auto it1 = it->second.begin();
            time = *it1;
            int prev = ((time[0]-'0')*10+time[1]-'0')*60+(time[3]-'0')*10+time[4]-'0';
            it1++, 
            time = *it1;
            int mid = ((time[0]-'0')*10+time[1]-'0')*60+(time[3]-'0')*10+time[4]-'0';
            it1++;
            for( ; it1 != it->second.end(); it1++)
            {
                time = *it1;
                int cur = ((time[0]-'0')*10+time[1]-'0')*60+(time[3]-'0')*10+time[4]-'0';
                if(cur-prev <= 60)
                {
                    ans.push_back(name);
                    break;
                }
                prev = mid;
                mid = cur;
            }
        }
        return ans;
    }
};