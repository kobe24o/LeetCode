class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int m = arr.back(), origin;
        arr.back() = -1;
        for(int i = arr.size()-2; i >= 0; --i)
        {
            origin = arr[i];
            arr[i] = m;
            m = max(m, origin);
        }
        return arr;
    }
};