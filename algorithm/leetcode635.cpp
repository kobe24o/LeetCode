class LogSystem {
    vector<long long> second = {12*31*24*3600, 31*24*3600, 24*3600, 3600, 60, 1};
    map<string, int> unit = {{"Year",0},{"Month",1},{"Day",2},{"Hour",3},{"Minute",4},{"Second",5}};
    map<long long, int> m;
public:
    LogSystem() {

    }

    void put(int id, string timestamp) {
        m[timeToint(timestamp)] = id;
    }

    vector<int> retrieve(string s, string e, string gra) {
        long long start = timeToint(s, unit[gra]);
        long long end = timeToint(e, unit[gra], true);
        vector<int> ans;
        for(auto it = m.lower_bound(start); it != m.end(); ++it)
        {
            if(it->first >= end)
                break;
            ans.push_back(it->second);
        }
        return ans;
    }
    long long timeToint(string& s, int g = 5, bool end = false)
    {	// 例如 2017:01:01:23:59:59
        long long Year = stoi(s.substr(0,4));
        long long Month = stoi(s.substr(5,2));
        long long Day = stoi(s.substr(8,2));
        long long Hour = stoi(s.substr(11,2));
        long long Minute = stoi(s.substr(14,2));
        long long Second = stoi(s.substr(17,2));
        long long t;
        if(g==5)
            t = (Year)*second[0]+(Month-1)*second[1]+(Day-1)*second[2]+(Hour)*second[3]+(Minute)*second[4]+(Second)*second[5];
        else if(g==4)
            t = (Year)*second[0]+(Month-1)*second[1]+(Day-1)*second[2]+(Hour)*second[3]+(Minute)*second[4];
        else if(g==3)
            t = (Year)*second[0]+(Month-1)*second[1]+(Day-1)*second[2]+(Hour)*second[3];
        else if(g==2)
            t = (Year)*second[0]+(Month-1)*second[1]+(Day-1)*second[2];
        else if(g==1)
            t = (Year)*second[0]+(Month-1)*second[1];
        else
            t = (Year)*second[0];
        t += end ? second[g] :0;
        return t;
    }
};