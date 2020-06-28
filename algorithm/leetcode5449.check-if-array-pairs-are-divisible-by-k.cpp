class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        multiset<int> s;
        for(auto a : arr)
            s.insert((a%k+k)%k);
        while(!s.empty())
        {
            int a = *s.begin();
            s.erase(s.begin());
            auto it = s.find((k-a)%k);
            if(it == s.end())
                return false;
            else
                s.erase(it);
        }
        return true;
    }
};

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k,0);
        for(auto a : arr)
            freq[(a%k+k)%k]++;
        if(freq[0]&1)
            return false;
        for(int i = 1; i <= k/2; ++i)
            if(freq[i] != freq[k-i])
                return false;
        return true;
    }
};