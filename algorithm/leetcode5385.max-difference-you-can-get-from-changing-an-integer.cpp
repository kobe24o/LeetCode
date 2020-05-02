class Solution {
public:
    int maxDiff(int num) {
        vector<int> big;
        int n = num, i = 0, first, idx;
        while(n)
        {
            big.insert(big.begin(),n%10);
            n /= 10;
        }
        vector<int> small(big);
        while(i < big.size())
        {
            if(big[i]==9)
                i++;
            else
                break;
        }
        if(i != big.size())
        {
            first = big[i];
            for( ; i < big.size(); ++i)
                if(big[i]==first)
                    big[i] = 9;
        }
        if(small[0]==1)
        {
            i = 1;
            while(i < big.size()) {
            if(small[i]<2)
                i++;
            else
                break;
            }
            if(i < big.size())
            {
                first = small[i];
                for( ; i < small.size(); ++i)
                    if(small[i]==first)
                        small[i] = 0;
            }
        }
        else
        {
            set<int> s;
            i = 0;
            int idx;
            for(; i < big.size(); ++i)
            {
                s.insert(small[i]);
            }
            if(s.size()==1)
            {

                for(i = 0 ; i < small.size(); ++i)
                        small[i] = 1;
            }
            else
            {
                first = small[0];
                for(i = 0 ; i < small.size(); ++i)
                    if(small[i]==first)
                        small[i] = 1;
            }
        }
        
        int a =0, b = 0;
        for(int i = 0; i < big.size(); ++i)
            a = a*10+big[i];
        for(int i = 0; i < big.size(); ++i)
            b = b*10+small[i];
        
        return a-b;
    }
};