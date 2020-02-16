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
        	scale = (tp-q.top()-1)/(s+1);
        	num = tp-scale*s;//栈顶-s，应该为1或者比1大的数
        	if(num < 1)//小于1则false
        		return false;
        	q.push(num);
        	sum -= s;//和减少了s
        }
        return true;
    }
};