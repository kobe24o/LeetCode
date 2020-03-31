class Solution {	//插入
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        int i, j;
        for(i = 0; i < arr.size(); ++i)
        {
        	for(j = i; j > 0; --j)
        	{
        		if(arr[j-1] > arr[j])
        			swap(arr[j-1],arr[j]);
        		else
        			break;
        	}
        }
        return arr;
    }
};

class Solution {	//冒泡
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        int i, j;
        bool arrSorted = false;
        for(i = 0; i < arr.size(); ++i)
        {
        	arrSorted = true;
        	for(j = 1; j <= arr.size()-1-i; ++j)
        	{
        		if(arr[j-1] > arr[j])
        		{
        			swap(arr[j-1],arr[j]);
        			arrSorted = false;
        		}
        	}
        	if(arrSorted)
        		break;
        }
        return arr;
    }
};

class Solution {	//选择
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        int i, j, minIdx = 0;
        for(i = 0; i < arr.size()-1; ++i)
        {
        	minIdx = i;
        	for(j = i+1; j < arr.size(); ++j)
        	{
        		if(arr[minIdx] > arr[j])
        			minIdx = j;
        	}
        	swap(arr[i],arr[minIdx]);
        }
        return arr;
    }
};

class Solution {	//希尔
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        int i, j, gap = 1;
        for(gap = arr.size()/2; gap > 0; gap /= 2)
        {
	        for(i = gap; i < arr.size(); ++i)
	        {
	        	for(j = i; j-gap >= 0 && arr[j-gap]>arr[j]; j -= gap)
	        		swap(arr[j-gap],arr[j]);
	        }
	    }
        return arr;
    }
};

class Solution {	//归并
	vector<int> temp;
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        temp.resize(arr.size());
        mergeSort(arr,0, arr.size()-1);
        return arr;
    }

    void mergeSort(vector<int>& arr, int l, int r)
    {
    	if(l == r)
    		return;
    	int mid = l+((r-l)>>1);
    	mergeSort(arr,l,mid);
    	mergeSort(arr,mid+1,r);
    	merge(arr,l,mid,r);
    }

    void merge(vector<int>& arr, int l, int mid, int r)
    {
    	int i = l, j = mid+1, k = 0;
    	while(i <= mid && j <= r)
    	{
    		if(arr[i] <= arr[j])
    			temp[k++] = arr[i++];
    		else
    			temp[k++] = arr[j++];
    	}
    	while(i <= mid)
    		temp[k++] = arr[i++];
    	while(j <= r)
    		temp[k++] = arr[j++];
    	for(k = 0, i = l; i <= r; ++i,++k)
    		arr[i] = temp[k];
    }
};

class Solution {	//快排
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        qsort(arr,0, arr.size()-1);
        return arr;
    }

    void qsort(vector<int>& arr, int l, int r)
    {
    	if(l >= r)
    		return;
    	int Pl = l, Pr = l;
    	partition(arr,l,r,Pl,Pr);
    	qsort(arr,l,Pl-1);
    	qsort(arr,Pr+1,r);
    }

    void partition(vector<int>& arr, int l, int r, int& Pl, int& Pr)
    {	
    	selectMid(arr,l,r);
    	int P = arr[l];
    	int i = l, j = r;
    	while(i < j)
    	{
    		while(i < j && P < arr[j])//没有等于号，哨兵都在左侧
    			j--;
    		swap(arr[i], arr[j]);
    		while(i < j && arr[i] <= P)
    			i++;
    		swap(arr[i], arr[j]);
    	}
    	Pl = Pr = i;
    	for(i = i-1; i >= l; --i)
    	{
    		if(arr[i] == P)
    		{
    			Pl--;
    			swap(arr[i], arr[Pl]);
    		}
    	}
    }

    void selectMid(vector<int>& arr, int l, int r)
    {
    	int mid = l+((r-l)>>1);
    	if(arr[mid] > arr[r])
    		swap(arr[mid],arr[r]);
    	if(arr[l] > arr[r])
    		swap(arr[l], arr[r]);
    	if(arr[mid] > arr[l])
    		swap(arr[mid], arr[l]);
    }
};

class Solution {	//堆排序, 建堆（升序建大堆，降序建小堆）
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        for(int i = arr.size()/2-1; i >= 0; --i)
    		adjust(arr,i,arr.size());//建堆
        for(int i = arr.size()-1; i >= 0; --i)
        {
        	swap(arr[i],arr[0]);
        	adjust(arr,0,i);
        }
        return arr;
    }

    void adjust(vector<int>& arr, int i, int len)
    {
    	int lchild = 2*i+1, rchild = 2*i+2, maxIdx = i;
    	while(lchild < len)
    	{
    		if(lchild < len && arr[lchild] > arr[maxIdx])
    			maxIdx = lchild;
    		if(rchild < len && arr[rchild] > arr[maxIdx])
    			maxIdx = rchild;
    		if(maxIdx != i)
    		{
    			swap(arr[i],arr[maxIdx]);
    			lchild = 2*maxIdx+1;
                rchild = lchild+1;
    			i = maxIdx;
    		}
            else
                break;
    	}
    }
};

class Solution {	//计数排序
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        int i, j = 0, min, max;
        min = max = arr[0];
        for(i = 1; i < arr.size(); ++i)
        {
        	min = arr[i] < min ? arr[i] : min;
        	max = arr[i] > max ? arr[i] : max;
        }
        const int N = max-min+1;
        vector<int> count(N,0);
        for(i = 0; i < arr.size(); ++i)
        	count[arr[i]-min]++;
        for(i = 0; i < N; ++i)
        {
        	while(count[i]--)
        		arr[j++] = i+min;
        }
        return arr;
    }
};


class Solution {    //桶排序
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
            return arr;
        int i, j = 0, min, max;
        min = max = arr[0];
        for(i = 1; i < arr.size(); ++i)
        {
            min = arr[i] < min ? arr[i] : min;
            max = arr[i] > max ? arr[i] : max;
        }
        if(min == max)
            return arr;
        int div = 10000;//桶个数
        int space = (max-min)/div+1;
        vector<int> temp(arr.size());
        vector<int> bucketsize(div,0);
        vector<int> bucketPos(div,0);
        for(i = 0; i < arr.size(); ++i)
            bucketsize[(arr[i]-min)/space]++;
        bucketPos[0] = bucketsize[0];
        for(i = 1; i < div; ++i)
            bucketPos[i] += bucketPos[i-1] + bucketsize[i];//桶结束位置的下一个
        for(i = 0; i < arr.size(); ++i)
            temp[--bucketPos[(arr[i]-min)/space]] = arr[i];
        for(i = 0; i < div; ++i)
        {
            if(bucketsize[i] > 1)
            {
                qsort(temp,bucketPos[i],bucketPos[i]+bucketsize[i]-1);
            }
        }
        for(i = 0; i < arr.size(); ++i)
            arr[i] = temp[i];
        return arr;
    }

    void qsort(vector<int>& arr, int l, int r)
    {
        if(l >= r)
            return;
        int Pl = l, Pr = l;
        partition(arr,l,r,Pl,Pr);
        qsort(arr,l,Pl-1);
        qsort(arr,Pr+1,r);
    }

    void partition(vector<int>& arr, int l, int r, int& Pl, int& Pr)
    {
        selectMid(arr,l,r);
        int P = arr[l];
        int i = l, j = r;
        while(i < j)
        {
            while(i < j && P < arr[j])//没有等于号，哨兵都在左侧
                j--;
            swap(arr[i], arr[j]);
            while(i < j && arr[i] <= P)
                i++;
            swap(arr[i], arr[j]);
        }
        Pl = Pr = i;
        for(i = i-1; i >= l; --i)
        {
            if(arr[i] == P)
            {
                Pl--;
                swap(arr[i], arr[Pl]);
            }
        }
    }

    void selectMid(vector<int>& arr, int l, int r)
    {
        int mid = l+((r-l)>>1);
        if(arr[mid] > arr[r])
            swap(arr[mid],arr[r]);
        if(arr[l] > arr[r])
            swap(arr[l], arr[r]);
        if(arr[mid] > arr[l])
            swap(arr[mid], arr[l]);
    }
};

class Solution {	//基数排序
	vector<int> temp;
public:
    vector<int> sortArray(vector<int>& arr) {
        if(arr.size() <= 1)
        	return arr;
        int i, max = INT_MIN;
        long exp;
        temp.resize(arr.size());
        for(i = 0; i < arr.size(); ++i)
        {
            arr[i] += 50000;//便于负数处理
            max = arr[i] > max ? arr[i] : max;
        }
        for(exp = 1; max/exp > 0; exp*=10)
        	radix_sort(arr,exp);

        for(i = 0; i < arr.size(); ++i)
            arr[i] -= 50000;//还原
        return arr;
    }
    void radix_sort(vector<int>& arr, long exp)
    {
	    vector<int> bucketsize(10,0);
        int i;
        for(i = 0; i < arr.size(); ++i)
        	bucketsize[(arr[i]/exp)%10]++;
        for(i = 1; i < 10; ++i)
        	bucketsize[i] += bucketsize[i-1];//桶最后一个位置+1
        for(i = arr.size()-1; i >= 0; --i)
        	temp[--bucketsize[(arr[i]/exp)%10]] = arr[i];
        for(i = 0; i < arr.size(); ++i)
        	arr[i] = temp[i];
	}
};