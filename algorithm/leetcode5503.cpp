解题：
- 先计算前缀和，再枚举子数组开始位置和奇数长度
- 时间复杂度 $O(n^2)$
```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), sum = 0;
        for(int i = 1; i < n; ++i) 
        {
            arr[i] = arr[i-1] + arr[i];
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int len = 1; len <= n; len+=2)
            {
                int j = i+len-1;
                if(j >= n)
                    break;
                sum += arr[j]- (i > 0 ? arr[i-1] : 0);
            }
        }
        return sum;
    }
};
```
4 ms    8 MB

- 参考[大佬的思路](https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/solution/cong-on3-dao-on-de-jie-fa-by-liuyubobobo/)
- 对每个数字考虑前后的奇偶数字的长度有多少种，前后同奇同偶的方案数相乘
```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), sum = 0;
        int L_odd, L_even, R_odd, R_even, L, R;
        for(int i = 0; i < n; ++i)
        {
            //对每个数字进行考察 1个数字
            //它的左边右边有的数字个数必须是同奇同偶
            //这样子数组才会是奇数个长度
            //有多少种组合
            L_odd = (i+1)/2;//奇数有这么多种选择
            L_even = i/2;
            R_odd = (n-i)/2;
            R_even = (n-i-1)/2;
            sum += (L_odd*R_odd + (L_even+1)*(R_even+1))*arr[i];
                                    // +1 为前后偶数个数为0的情况
        }
        return sum;
    }
};
```
0 ms    8.1 MB
