struct cmp
{
    bool operator()(const pair<int,double>& a, const pair<int,double>& b)const
    {
        return a.second < b.second;//概率大的优先
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,unordered_map<int,double>> m;
        for(int i = 0; i < edges.size(); ++i)
        {
            m[edges[i][0]][edges[i][1]] = succProb[i];
            m[edges[i][1]][edges[i][0]] = succProb[i];
        }
        vector<double> prob(n,0.0);
        prob[start] = 1.0;
        priority_queue<pair<int,double>,vector<pair<int,double>>,cmp> q;
        q.push({start, 1.0});
        while(!q.empty())
        {
            int i = q.top().first, j;
            double p = q.top().second, pij;
            q.pop();
            for(auto it = m[i].begin(); it != m[i].end(); ++it)
            {
                j = it->first;
                pij = it->second;
                if(p*pij > prob[j])
                {
                    prob[j] = p*pij;
                    q.push({j, prob[j]});
                }
            }
        }
        return prob[end];
    }
};
