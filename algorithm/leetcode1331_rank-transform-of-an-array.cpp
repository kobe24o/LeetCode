class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        multimap<int,int> m;
        for (int i = 0; i < arr.size(); ++i)
        {
            m.insert(make_pair(arr[i],i));
        }
        int count = 0, prev = INT_MIN;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if(prev != it->first)//map有序，数值与前面的不相等，排名增加
            {
                count++;//排名
                prev = it->first;
            }
            arr[it->second] = count;//原来数的位置，写成排名
        }
        return arr;
    }
};