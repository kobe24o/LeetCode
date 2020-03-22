class Solution {    //超时
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& Seats) {
        int count = 0, line = 1, i = 0;
        sort(Seats.begin(), Seats.end(),[&](auto a, auto b){
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        for(line = 1; line <= n; ++line)
        {   
            bitset<11> b;
            while(i < Seats.size() && Seats[i][0] == line)
            {
                b.set(Seats[i][1], 1);
                i++;
            }
            if(b.count() == 0 || (!b[2]&&!b[3]&&!b[4]&&!b[5]&&!b[6]&&!b[7]&&!b[8]&&!b[9]))
                count += 2;
            else if((!b[2]&&!b[3]&&!b[4]&&!b[5]) && (b[6]||b[7]||b[8]||b[9]))
                count += 1;
            else if((!b[6]&&!b[7]&&!b[8]&&!b[9]) && (b[2]||b[3]||b[4]||b[5]))
                count += 1;
            else if((!b[4]&&!b[5]&&!b[6]&&!b[7])&& (b[2]||b[3]) && (b[8]||b[9]))
                count += 1;
        }
        return count;
    }
};

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& Seats) {
        int count = 0, line = 1, i = 0;
        map<int,bitset<11>> m;
        for(auto& st : Seats)
        {
            m[st[0]].set(st[1]);
        }
        bitset<11> b;
        for(auto& mi : m)
        {   
            b = mi.second;
            if(b.count() == 0 || (!b[2]&&!b[3]&&!b[4]&&!b[5]&&!b[6]&&!b[7]&&!b[8]&&!b[9]))
                count += 2;
            else if((!b[2]&&!b[3]&&!b[4]&&!b[5]) && (b[6]||b[7]||b[8]||b[9]))
                count += 1;
            else if((!b[6]&&!b[7]&&!b[8]&&!b[9]) && (b[2]||b[3]||b[4]||b[5]))
                count += 1;
            else if((!b[4]&&!b[5]&&!b[6]&&!b[7])&& (b[2]||b[3]) && (b[8]||b[9]))
                count += 1;
        }
        return count+2*(n-m.size());
    }
};