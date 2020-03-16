class Solution {
	int sum = 0;
	vector<int> temp;
public:
    int reversePairs(vector<int>& nums) {
        temp.resize(nums.size());
    	mergesort(nums,0,nums.size()-1);
    	return sum;
    }

    void mergesort(vector<int>& arr, int l ,int r)
    {
    	if(l >= r)
    		return;
    	int mid = l + ((r-l)>>1);
    	mergesort(arr,l,mid);
    	mergesort(arr,mid+1,r);
    	merge(arr,l,mid,r);
    }

    void merge(vector<int>& arr, int l, int mid, int r)
    {
    	int i = l, j = mid+1, k = 0;
    	// 方法1：后半部出队，sum+前半部 没有出来的个数(比后面大的)
    	while(i <= mid && j <= r)
    	{
    		if(arr[i] <= arr[j])
    			temp[k++] = arr[i++];
    		else
    		{
    			temp[k++] = arr[j++];
    			sum += mid-i+1;
    		}
    	}
    	while(i <= mid)//后面都出完了，前半部还剩一些
    		temp[k++] = arr[i++];
    	while(j <= r)
    		temp[k++] = arr[j++];
    	for(i = l,j = 0; j < k; )
    		arr[i++] = temp[j++];
		//---------------------------------------------------
    	//方法2：前半部出队，sum+ 后半部 已经出队的数量(比前面的小)
    	while(i <= mid && j <= r)
    	{
    		if(arr[i] <= arr[j])
    		{
    			temp[k++] = arr[i++];
    			sum += j-(mid+1);
    		}
    		else
    			temp[k++] = arr[j++];
    	}
    	while(i <= mid)//后面都出完了，前半部还剩一些，还需要操作
    	{
    		temp[k++] = arr[i++];
    		sum += j-(mid+1);
    	}
    	while(j <= r)
    		temp[k++] = arr[j++];
    	for(i = l, j = 0; j < k; )
    		arr[i++] = temp[j++];
    }
};