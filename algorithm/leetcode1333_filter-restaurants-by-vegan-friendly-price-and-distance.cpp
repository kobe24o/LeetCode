class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int i;
        vector<vector<int>> temp;
        if(veganFriendly==1)
        {
            for(i = 0; i < restaurants.size(); ++i)
            {
                if(restaurants[i][2]==1 && restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
                    temp.push_back(restaurants[i]);
            }
        }
        else
        {
            for(i = 0; i < restaurants.size(); ++i)
            {
                if(restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance)
                    temp.push_back(restaurants[i]);
            }
        }
        
        sort(temp.begin(),temp.end(),[](const auto& a, const auto& b)
             {
                 if(a[1]==b[1])
                     return a[0] > b[0];
                 return a[1] > b[1];
             });
        
        vector<int> ans;
        for(const auto& r : temp)
            ans.push_back(r[0]);
        return ans;
    }
};