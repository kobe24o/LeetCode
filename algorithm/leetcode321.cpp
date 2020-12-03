class Solution {
    vector<int> tmp;
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        tmp.resize(k);
        int r = min(n1, k);
        vector<int> ans;
        for(int i = 0; i <= r; ++i)
        {
            if(k-i > n2)
                continue;
            auto arr1 = select(nums1, i);
            auto arr2 = select(nums2, k-i);
            merge(arr1, arr2, ans);
        }
        return ans;
    }
    vector<int> select(vector<int>& nums, int k)
    {
        if(k == nums.size())
            return nums;
        vector<int> stk;
        for(int i = 0; i < nums.size(); ++i)
        {
            while(!stk.empty() && stk.size()+nums.size()-i > k && stk.back() < nums[i])
                stk.pop_back();
            stk.push_back(nums[i]);
        }
        stk.resize(k);
        return stk;
    }
    void merge(vector<int>& a1, vector<int>& a2, vector<int>& ans)
    {
        int n1 = a1.size(), n2 = a2.size(), i = 0, j = 0, idx = 0;
        while(i < n1 && j < n2)
        {
            if(compare(a1, i, a2, j) >= 0)
                tmp[idx++] = a1[i++];
            else
                tmp[idx++] = a2[j++];
        }
        while(i < n1)
            tmp[idx++] = a1[i++];
        while(j < n2)
            tmp[idx++] = a2[j++];
        if(ans.empty())
            ans = tmp;
        else if(ans < tmp)
            ans = tmp;
    }
    int compare(vector<int>& a1, int i, vector<int>& a2, int j)
    {
        int n1 = a1.size(), n2 = a2.size();
        while(i < n1 && j < n2)
        {
            int diff = a1[i] - a2[j];
            if(diff != 0)
                return diff;
            i++,j++;
        }
        return (n1-i)-(n2-j);//相等话，有剩余的先取
    }
};