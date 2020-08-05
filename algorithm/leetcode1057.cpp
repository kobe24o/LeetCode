class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<int>> dis_w_b;
        int dis, count = 0;
        for(int i = 0; i < workers.size(); i++)
        {
            for(int j = 0; j < bikes.size(); j++)
            {
                dis = abs(workers[i][0]-bikes[j][0])+ abs(workers[i][1]-bikes[j][1]);
                dis_w_b.push_back({dis,i,j});
            }
        }
        sort(dis_w_b.begin(), dis_w_b.end());
        vector<bool> vis_w(workers.size(), false);
        vector<bool> vis_b(bikes.size(), false);
        vector<int> ans(workers.size());
        for(int i = 0; i < dis_w_b.size(); ++i)
        {
            if(vis_w[dis_w_b[i][1]] || vis_b[dis_w_b[i][2]])
                continue;
            ans[dis_w_b[i][1]] = dis_w_b[i][2];
            vis_w[dis_w_b[i][1]] = true;
            vis_b[dis_w_b[i][2]] = true;
            if(++count == workers.size())
                break;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<int>> dis_w_b;
        int dis, count = 0;
        for(int i = 0; i < workers.size(); i++)
        {
            for(int j = 0; j < bikes.size(); j++)
            {
                dis = abs(workers[i][0]-bikes[j][0])+ abs(workers[i][1]-bikes[j][1]);
                dis_w_b.push_back({dis,i,j});
            }
        }
        sort(dis_w_b.begin(), dis_w_b.end());
        vector<bool> vis_w(workers.size(), false);
        vector<bool> vis_b(bikes.size(), false);
        vector<int> ans(workers.size());
        for(int i = 0; i < dis_w_b.size(); ++i)
        {
            if(vis_w[dis_w_b[i][1]] || vis_b[dis_w_b[i][2]])
                continue;
            ans[dis_w_b[i][1]] = dis_w_b[i][2];
            vis_w[dis_w_b[i][1]] = true;
            vis_b[dis_w_b[i][2]] = true;
            if(++count == workers.size())
                break;
        }
        return ans;
    }
};