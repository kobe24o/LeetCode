class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), i = 1, ans = arr[0], t=k;
        while(t-- && i < n)//模拟k次
        {
            if(ans < arr[i])//碰见比我大的
            {
                ans = arr[i];//更改答案
                t = k-1;//该大数，还要模拟k-1次
            }
            i++;
        }
        return ans;
    }
};