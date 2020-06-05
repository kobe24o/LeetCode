class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int bits = countbits(low), num, delta;
        string s19 = "1234567890", s11 = "1111111111";
        num = stoi(s19.substr(0,bits));
        vector<int> ans;
        while(num <= high)
        {
            delta = stoi(s11.substr(0,bits));
            while(num%10 != 0 && num <= high)
            {
                if(num >= low)
                    ans.push_back(num);
                num += delta;
            }
            bits++;
            num = stoi(s19.substr(0,bits));
        }
        return ans;
    }
    int countbits(int n)
    {
        int count = 0;
        while(n)
        {
            count++;
            n /= 10;
        }
        return count;
    }
};