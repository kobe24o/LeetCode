class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size()) return -1;
        int l = 1, r = 1e9, mid;
        while(l < r)
        {
            mid = l+((r-l)>>1);
            if(haveflower(bloomDay, mid, m, k))
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
    bool haveflower(vector<int>& day, int days, int m, int k) 
    {
        int flowerPack = 0, flowercount = 0;
        for(auto d : day)
        {
            if(days/d >= 1)//能开花
                flowercount++;
            else
                flowercount = 0;
            if(flowercount == k)
            {
                flowerPack++;
                flowercount = 0;
            }
        }
        return flowerPack >= m;
    }
};