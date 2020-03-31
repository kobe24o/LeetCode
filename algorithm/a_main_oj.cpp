#include <bits/stdc++.h>

using namespace std;

class Solution {	//桶排序
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
        int div = 2;//桶个数
        int space = (max-min)/div+1;
        vector<int> temp(arr.size());
        vector<int> bucketsize(div,0);
        vector<int> bucketPos(div,0);
        for(i = 0; i < arr.size(); ++i)
            bucketsize[(arr[i]-min)/space]++;
        bucketPos[0] = bucketsize[0];
        for(i = 1; i < arr.size(); ++i)
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

int main() {
    Solution s;
    vector<int> v = {2,3,1,4,2,3};

    s.sortArray(v);
    for(auto& vi : v)
        cout << vi <<" ";
}