class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> age(121, 0);//每个年龄有多少人
        for(auto a : ages) 
            age[a]++;
        vector<int> sum(121,0);
        for(int i = 1; i <= 120; i++)
        {
            sum[i] += sum[i-1]+age[i];// 前缀人数和
        }
        int ans = 0, l, r;
        for(int i = 15; i <= 120; i++)
        {
            l = i/2 + 7;
            r = i;
            ans += (sum[r-1]-sum[l])*age[i]+age[i]*(age[i]-1);
            //  年龄小于当前的，满足条件的人* 每人都可以发
            //  + 当前同龄里的人，互相发
        }
        return ans;
    }
};