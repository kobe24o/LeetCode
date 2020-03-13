class Solution {
public:
    long long doingHomework(vector<int> &cost, vector<int> &val) {
        // Write your code here.
        long long sum = 0;
        int i, j;
        for(i = 0; i < cost.size(); ++i)
        {
            sum += cost[i];
            cost[i] = sum;
        }
        sort(val.begin(),val.end());
        sum = 0;
        for(i = 0; i < val.size(); ++i)
        {
            if(val[i] > cost.back())
            {
                sum += cost.back();
                continue;
            }
            j = bs(cost,val[i]);
            if(j != -1)
                sum += cost[j];
        }
        return sum;
    }
    
    int bs(vector<int>& cost, int v)
    {
        int l = 0, r = cost.size()-1, mid;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            if(cost[mid] > v)
            {
                r = mid -1;
            }
            else
            {
                if(mid==cost.size()-1 || cost[mid+1] > v)
                    return mid;
                else
                    l = mid+1;
            }
        }
        return -1;
    }
};