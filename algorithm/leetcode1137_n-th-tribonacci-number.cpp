class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        int result, n_3 = 0, n_2 =1, n_1 = 1;
        for(int i = 3; i <= n; ++i)
        {
        	result = n_1 + n_2 + n_3;
        	n_3 = n_2;
        	n_2 = n_1;
        	n_1 = result;
        }
        return result;
    }
};