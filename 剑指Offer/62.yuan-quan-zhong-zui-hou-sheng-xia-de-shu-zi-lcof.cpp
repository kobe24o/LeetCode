class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> num(n);
        int i;
        for(i = 0; i < n; i++)
        	num[i] = i;
        i = 0;
        while(num.size() != 1)
        {
        	num.erase(num.begin()+(i+m-1)%num.size());
        	i--;
        }
        return num[0];
    }
};

class Solution {
public:
    int lastRemaining(int n, int m) {
        int pos = 0;//1个人时
        for(int i = 2; i <= n; i++)
        {	//i表示人数
        	pos = (pos+m)%i;
        }
        return pos;
    }
};