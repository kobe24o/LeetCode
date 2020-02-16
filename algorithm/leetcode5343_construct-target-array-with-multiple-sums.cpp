class Solution {
public:
    bool isPossible(vector<int>& target) {
        int i, num;
        long sum = 0, s;
        priority_queue<int> q;//默认大顶堆
        for(i = 0; i < target.size(); ++i)
        {
        	sum += target[i];
        	q.push(target[i]);
        }
        while(q.top() != 1)
        {
        	s = sum-q.top();
        	num = q.top()-s;
        	if(num < 1)
        		return false;
        	q.pop();
        	q.push(num);
        	sum -= s;
        }
        return true;
    }
};