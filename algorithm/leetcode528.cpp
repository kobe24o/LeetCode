class Solution {
    vector<int> w_presum;
    int total;
public:
    Solution(vector<int>& w) {
        w_presum = w;
        for(int i = 1; i < w.size(); ++i)
            w_presum[i] += w_presum[i-1];
        total = w_presum.back();
    }
    
    int pickIndex() {
        int w = rand()%total + 1;
        int L = 0, R = w_presum.size()-1, mid;
        while(L <= R)
        {
            mid = L+((R-L)>>1);
            if(w_presum[mid] < w)
                L = mid+1;
            else
            {
                if(mid==0 || w_presum[mid-1] < w)
                    return mid;
                else
                    R = mid-1;
            }
        }
        return -1;
    }
};