class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> v(hi-lo+1);
        int j = 0;
        for(int i = lo; i <= hi; i++)
            v[j++] = i;
        sort(v.begin(), v.end(),[&](int a, int b) {
            int wa = calw(a), wb = calw(b);
            if(wa == wb)
                return a < b;
            return wa < wb;
        });
        return v[k-1];
    }

    int calw(int x)
    {
        int count = 0;
        while(x != 1)
        {
            if(x%2)
                x = 3*x+1;
            else
                x = x/2;
            count++;
        }
        return count;
    }
};