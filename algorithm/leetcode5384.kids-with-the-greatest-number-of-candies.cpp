class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int i, j, k = 0, n = candies.size();
        bool flag = true;
        vector<bool> ans(n,false);
        for(i = 0; i < n; ++i)
        {
            flag = true;
            for(j = 0; j < n; ++j)
            {
                if(candies[i]+extraCandies < candies[j])
                {
                    flag = false;
                    break;
                }
            }
            ans[k++] = flag;
        }
        return ans;
    }
};
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int i, j=0, maxCandy = *max_element(candies.begin(),candies.end()), n = candies.size();
        vector<bool> ans(n,false);
        for(i = 0; i < n; ++i)
        {
            ans[j++] = (candies[i]+extraCandies >= maxCandy);
        }
        return ans;
    }
};