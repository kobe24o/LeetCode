class MedianFinder {
	priority_queue<int> MaxHeap;//大顶堆
	priority_queue<int,vector<int>,greater<int>> MinHeap;//小顶堆
	//大堆存较小的部分，小堆存较大的部分，大堆size-小堆size = 0 or 1
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(MaxHeap.size() > MinHeap.size())
        {
        	if(num >= MaxHeap.top())
        		MinHeap.push(num);
        	else
        	{
        		MinHeap.push(MaxHeap.top());
        		MaxHeap.pop();
        		MaxHeap.push(num);
        	}
        }
        else//size相等
        {
        	if(MaxHeap.empty())
        		MaxHeap.push(num);
        	else
        	{
        		if(num <= MinHeap.top())
        			MaxHeap.push(num);
	        	else
	        	{
	        		MaxHeap.push(MinHeap.top());
	        		MinHeap.pop();
	        		MinHeap.push(num);
	        	}
        	}
        }
    }
    
    double findMedian() {
        if(MaxHeap.size() == MinHeap.size())
        	return (MaxHeap.top() + MinHeap.top())/2.0;
        return MaxHeap.top();
    }
};