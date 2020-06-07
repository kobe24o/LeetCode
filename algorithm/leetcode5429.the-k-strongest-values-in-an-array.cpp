class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mid = arr[(n-1)>>1];
        sort(arr.begin(), arr.end(),[&](auto a, auto b){
            return (abs(a-mid) > abs(b-mid)) || (abs(a-mid) == abs(b-mid) && a > b);
        });
        return vector<int> (arr.begin(),arr.begin()+k);
    }
};