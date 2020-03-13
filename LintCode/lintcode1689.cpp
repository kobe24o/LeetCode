class Solution {
    int sum = 0;
    int t;
public:
    int getAns(vector<int> &a, int k, int target) {
        if(target <= 0)
            return 0;
        t = target;
        vector<int> odd, even;
        for(auto& ai : a)
        {
            if(ai%2)
                odd.push_back(ai);
            else
                even.push_back(ai);
        }
        dfs(odd,0,0,0,k);
        dfs(even,0,0,0,k);
        return sum;
    }

    void dfs(vector<int> &v, int idx, int count, int s,int& k)
    {
        if(s >= t || count ==k)
        {
            if((s == t) && (count == k))
                sum++;
            return;
        }
        for(int i = idx; i < v.size(); ++i)
        {
            dfs(v,i+1,count+1,s+v[i],k);
        }
    }
};