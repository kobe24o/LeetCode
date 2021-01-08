class Solution { // 超时
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> a, b, ans;
        for(int i = 0; i < n; ++i)
        {
            b.clear();
            b.insert(arr[i]);
            for(auto it = a.begin(); it != a.end(); ++it)
            {
                b.insert(*it|arr[i]);
            }
            a.swap(b);
            for(auto i : a)
                ans.insert(i);
        }
        return ans.size();
    }
};

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> ans;
        for(int i = 0; i < n; ++i)//以 i 为右端点
        {
            ans.insert(arr[i]);
            for(int j = i-1; j >= 0; --j) // j 为左端点
            {
                if((arr[j]|arr[i])==arr[j])
                    break;//arr[j] 存储的是 [j, i-1] 的区间 | 和
                arr[j] |= arr[i]; //现在 arr[j] 存储的是 [j, i] 的区间 | 和
                ans.insert(arr[j]);
            }
        }
        return ans.size();
    }
};