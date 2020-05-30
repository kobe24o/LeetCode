class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        int i, n = h.size(), maxArea = 0, prevH, width;
        stack<int> s;//单调递增栈，存储下标
        for(i = 0; i < h.size(); ++i)
        {
        	while(!s.empty() && h[s.top()] > h[i])//前面大于我的
        	{
        		prevH = h[s.top()];
        		s.pop();
        		width = (s.empty() ? i : i-s.top()-1);
        		maxArea = max(maxArea, prevH*width);
        	}
        	s.push(i);
        }
        return maxArea;
    }
};