class Solution {//超时
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int i = 0, j = 0, count = 0, c = 0, x, y, m = nums.size(),n=0, finishi = -1;
        vector<int> precount(nums.size(),0);
        for(i = 0; i < m; ++i)
        {
            count += nums[i].size();
            n = max(n, int(nums[i].size()));
        }
        x = y = i = j = 0;
        while(c < count)
        {
            i = x, j = y;
            while(i>=0 && j<n && c<count)
            {
                if(j < nums[i].size())
                {
                    ans.push_back(nums[i][j]);
                    c++;
                    precount[i]++;
                    if(precount[i]==nums[i].size())
                    {
                        if(precount[finishi+1] == nums[finishi+1].size())
                            finishi++;
                    }
                }
                i--;
                j++;
                if(i <= finishi)
                    break;
            }
            x++;
            if(x >= m)
            {
                x = m-1;
                y++;
            }
        }
        return ans;
    }
};

class Solution {    //超时
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int i, j;
        vector<vector<int>> v; //posx+posy, posx, val
        for(i = 0; i < nums.size(); ++i)
        {
            for(j = 0; j < nums[i].size(); ++j)
            {
                v.push_back({i+j, i, nums[i][j]});
            }
        }
        sort(v.begin(), v.end(),[&](auto a, auto b){
            if(a[0]==b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> ans(v.size());
        i = 0;
        for(auto& vi : v)
            ans[i++] = vi[2];
        return ans;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int i, j, size = 0;
        map<int,map<int,int>> m;//posx+posy, posx, val
        for(i = 0; i < nums.size(); ++i)
        {
            for(j = 0; j < nums[i].size(); ++j)
            {
                m[i+j][i] = nums[i][j];
                size++;
            }
        }
        
        vector<int> ans(size);
        i = 0;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            for(auto it1 = it->second.rbegin(); it1 != it->second.rend(); ++it1)
                ans[i++] = it1->second;
        }
        return ans;
    }
};