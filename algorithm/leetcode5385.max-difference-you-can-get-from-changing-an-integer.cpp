class Solution {
public:
    int maxDiff(int num) {
        vector<int> big;
        int n, i = 0, first;
        while(num)
        {
            big.insert(big.begin(),num%10);
            num /= 10;
        }
        vector<int> small(big);
        n = big.size();
        while(i < n)
        {
            if(big[i]==9)
                i++;
            else
                break;
        }
        if(i != n)
        {
            first = big[i];
            for( ; i < n; ++i)
                if(big[i]==first)
                    big[i] = 9;//换成9
        }
        if(small[0]==1)//首位是1
        {
            i = 1;
            while(i <n) 
            {
                if(small[i]<2)
                    i++;
                else
                    break;
            }
            if(i < n)//大于等 2 的 i
            {
                first = small[i];
                for( ; i < n; ++i)
                    if(small[i]==first)
                        small[i] = 0;//都变成0
            }
        }
        else//首位 >= 2
        {
            set<int> s;
            for(i = 0; i < n; ++i)
                s.insert(small[i]);
            if(s.size()==1)//全部一样
            {
                for(i = 0 ; i < small.size(); ++i)
                    small[i] = 1;//都变成1
            }
            else//不都一样把首位变成1
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

class Solution {
public:
    int maxDiff(int num) {
        vector<int> big;
        int n, i = 0, first;
        while(num)
        {
            big.insert(big.begin(),num%10);
            num /= 10;
        }
        vector<int> small(big);
        n = big.size();
        while(i < n)
        {
            if(big[i]==9)
                i++;
            else
                break;
        }
        if(i != n)
        {
            first = big[i];
            for( ; i < n; ++i)
                if(big[i]==first)
                    big[i] = 9;//换成9
        }
        i = 0;
        while(i < n) 
        {
            if(small[i]<2)
                i++;
            else
                break;
        }
        if(i < n)
        {
            first = small[i];
            if(first == small[0])//等于高位
            {
                for(i = 0; i < n; ++i)
                    if(small[i]==first)
                        small[i] = 1;//都变成1
            }
            else//不等于高位
            {
                for(i = 0; i < n; ++i)
                    if(small[i]==first)
                        small[i] = 0;//都变成0
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