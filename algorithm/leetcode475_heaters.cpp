class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        //为处理边界方便增加两个虚拟无穷远加热站
        heaters.push_back(INT_MAX);
        heaters.push_back(-1e10);
        sort(heaters.begin(),heaters.end());
        int i = 0, j = 0, r = 0;
        while(i < houses.size())
        {
        	if(houses[i] >= heaters[j] && houses[i] <= heaters[j+1])
        	{
        		r = max(r,min(house[i]-heaters[j], heaters[j+1]-houses[i]));
        		++i;
        	}
        	else
        		++j;
        }
        return r;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(INT_MAX);
        heaters.push_back(-1e9-1);
        sort(heaters.begin(),heaters.end());
        int i = 0, prev, next, r = 0;
        for(i = 0; i < houses.size(); ++i)
        {
            prev = 0; next = heaters.size()-1;
            binarysearch(houses[i],heaters,prev,next);
            r = max(r,min(houses[i]-heaters[next], heaters[prev]-houses[i]));
        }
        return r;
    }

    void binarysearch(int p, vector<int> &heaters, int &i, int &j)
    {
        int mid;
        while(i <= j)
        {
            mid = i+((j-i)>>1);
            if(p < heaters[mid])
                j = mid-1;
            else if(p > heaters[mid])
                i = mid+1;
            else
            {
                i = j = mid;
                return;
            }
        }
    }
};