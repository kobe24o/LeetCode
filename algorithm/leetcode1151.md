
@[TOC]

## 1. 题目

给出一个二进制数组 data，你需要通过交换位置，将数组中 任何位置 上的 1 组合到一起，并返回所有可能中所需 最少的交换次数。

 
```cpp
示例 1：
输入：[1,0,1,0,1]
输出：1
解释： 
有三种可能的方法可以把所有的 1 组合在一起：
[1,1,1,0,0]，交换 1 次；
[0,1,1,1,0]，交换 2 次；
[0,0,1,1,1]，交换 1 次。
所以最少的交换次数为 1。

示例 2：
输入：[0,0,0,1,0]
输出：0
解释： 
由于数组中只有一个 1，所以不需要交换。

示例 3：
输入：[1,0,1,0,1,0,0,1,1,0,1]
输出：3
解释：
交换 3 次，一种可行的只用 3 次交换的解决方案是 [0,0,0,0,0,1,1,1,1,1,1]。
 
提示：
1 <= data.length <= 10^5
0 <= data[i] <= 1
```


>来源：力扣（LeetCode）
>链接：https://leetcode-cn.com/problems/minimum-swaps-to-group-all-1s-together
>著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


## 2. 解题
- 先计算出有多少个1，假设为k个
- 然后用一个固定大小为k的窗口，遍历数组，记录窗口内0的最小个数即为答案

```cpp
class Solution {
public:
    int minSwaps(vector<int>& data) {
    	int one = 0, i, j, minsp = INT_MAX;
    	for(i = 0; i < data.size(); ++i)
    	{
    		if(data[i])
    			one++;
    	}
    	i = 0; j = 0;
    	int count = 0;
    	while(j < one-1)
    	{
    		if(data[j++])
    			count++;
    	}
    	for( ; j < data.size(); ++j)
    	{
    		if(data[j])
    			count++;
    		minsp = min(minsp, one-count);
    		if(data[i++])
    			count--;
    	}
    	return minsp;
    }
};
```
208 ms	64.5 MB


---

我的CSDN[博客地址 https://michael.blog.csdn.net/](https://michael.blog.csdn.net/)

长按或扫码关注我的公众号（Michael阿明），一起加油、一起学习进步！
![Michael阿明](https://img-blog.csdnimg.cn/20200630084921292.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzIxMjAxMjY3,size_16,color_FFFFFF,t_70)