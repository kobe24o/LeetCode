class MedianFinder {
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;
	int n = 0;
public:
    MedianFinder() {}
    
    void addNum(int num) {
    	++n;
    	if(maxHeap.empty())
    		maxHeap.push(num);
    	else if(maxHeap.size() <= minHeap.size())
    	{
    		if(num > minHeap.top())
    		{
    			maxHeap.push(minHeap.top());
    			minHeap.pop();
    			minHeap.push(num);
    		}
    		else
    			maxHeap.push(num);
    	}
    	else// maxHeap.size() > minHeap.size()
    	{
    		if(num < maxHeap.top())
    		{
    			minHeap.push(maxHeap.top());
    			maxHeap.pop();
    			maxHeap.push(num);
    		}
    		else
    			minHeap.push(num);
    	}
    }
    
    double findMedian() {
        if(n%2 == 1)
        	return maxHeap.top();
        return (maxHeap.top()+minHeap.top())/2.0;
    }
};