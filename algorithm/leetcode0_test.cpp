/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0, s, i, num, tp, scale;
        priority_queue<long> q;//默认大顶堆
        for(i = 0; i < target.size(); ++i)
        {
            sum += target[i];//总和
            q.push(target[i]);
        }
        while(q.top() != 1)
        {
            tp = q.top();
            q.pop();
            s = sum-tp;//剩余的和
            scale = (tp-q.top()-1)/s;
            num = tp-scale*s;//栈顶-s，应该为1或者比1大的数
            if(num < 1)//小于1则false
                return false;
            q.push(num);
            sum -= scale*s;//和减少了s
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> v = {10000000,1};
    cout << s.isPossible(v);
}