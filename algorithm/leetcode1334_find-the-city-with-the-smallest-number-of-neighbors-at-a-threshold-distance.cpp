class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for(int i = 0; i < n; ++i)
            dis[i][i] = 0;

        for(int i = 0; i < n; ++i)
        {
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
            q.push({0,i});//第一个是距离，第二个是点的序号
            int from, to, distance;
            while(!q.empty())
            {
                from = q.top().second;
                q.pop();
                for(const auto& e : edges)
                {
                    if(from == e[0]){
                        to = e[1];
                        distance = e[2];
                        if(dis[i][from]+distance < dis[i][to])
                        {
                            dis[i][to] = dis[i][from]+distance;
                            q.push({dis[i][to], to});
                        }
                    }
                    else if(from == e[1]){
                        to = e[0];
                        distance = e[2];
                        if(dis[i][from]+distance < dis[i][to])
                        {
                            dis[i][to] = dis[i][from]+distance;
                            q.push({dis[i][to], to});
                        }
                    }
                }
            }
        }

        int count[n]={0};
        for(int i = 0; i < n; ++i)
            for(auto& d : dis[i])
                if(d <= distanceThreshold)
                    count[i]++;

        int minVal = INT_MAX, idx;
        for(int i = 0; i < n; ++i)
        {
            if(count[i] <= minVal)
            {
                minVal = count[i];
                idx = i;
            }
        }
        return idx;
    }
};