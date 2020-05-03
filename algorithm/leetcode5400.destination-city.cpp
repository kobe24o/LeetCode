class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> dist;
        unordered_set<string> start;
        for(auto p : paths)
        {
            start.insert(p[0]);//加入起点
            if(dist.count(p[0]))//目的地包含出发
                dist.erase(p[0]);//删除
            if(!start.count(p[1]))//不是起点
                dist.insert(p[1]);//插入终点集合
            else//p[1]是起点
            {
                if(dist.count(p[1]))
                    dist.erase(p[1]);//终点中删除
            }
        }
        return *dist.begin();
    }
};
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> in;
        unordered_map<string,int> out;
        for(auto p : paths)
        {
            out[p[0]]++;
            in[p[1]]++;
        }
        for(auto in_ : in)
        {
            if(out[in_.first]==0)
                return in_.first;
        }
        return "";
    }
};