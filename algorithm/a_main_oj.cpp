#include <bits/stdc++.h>

using namespace std;
void print2Dvector(vector<vector<int>>& a)
{
    int m = a.size(), n = a[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

class MKAverage {
    int m, k;
    long long sum = 0;
    queue<int> q;
    multiset<int> big, mid;
    multiset<int, greater<int>> small;
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        if(q.size() < m)
        {
            q.push(num);
            big.insert(num);
            process();
        }
        else
        {
            int tp = q.front();
            q.pop();
            q.push(num);
            big.insert(num);
            if(mid.find(tp) != mid.end())
            {
                sum -= tp;
                mid.erase(mid.find(tp));
            }
            else if(big.find(tp) != big.end())
                big.erase(big.find(tp));
            else // (small.find(tp) != small.end())
                small.erase(small.find(tp));
            process();
        }
    }

    void process()
    {
        while(big.size() > k)
        {
            small.insert(*big.begin());
            big.erase(big.begin());
        }
        while(small.size() > k)
        {
            mid.insert(*small.begin());
            sum += *small.begin();
            small.erase(small.begin());
        }
        if(big.size()+mid.size()+small.size() < m)
            return;
        if(big.size() < k)
        {
            auto it = --mid.end();
            sum -= *it;
            big.insert(*it);
            mid.erase(it);
        }
        if(small.size() < k)
        {
            auto it = mid.begin();
            sum -= *it;
            small.insert(*it);
            mid.erase(it);
        }
    }
    int calculateMKAverage() {
        if(q.size() < m)
            return -1;
        return sum/(m-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */


int main()
{

//    Solution s;
    vector<vector<int>> g = {{1,2,4},{3,4,3},{2,3,10}};
    vector<int> a = {352171103,442454244,42644624,152727101,413370302,293999243}, b = {6,2,6,6,1,1,4,6,4,6,2,5,4,2,1};
    string str = "9";
    string s1 = "guguuuuuuuuuuuuuuguguuuuguug",
           s2=     "gguggggggguuggguugggggg";
//    cout << s.largestMerge(s1,s2) << endl;
    vector<int> arr = {1,2,3,4,5,6};
    arr.reserve(4);
    for(auto a : arr)
        cout << a << endl;
//    cout << s.countNicePairs(a) << endl;
    MKAverage obj = MKAverage(3, 1);
    obj.addElement(58916);        // 当前元素为 [3]
    obj.addElement(61899);        // 当前元素为 [3,1]
    cout << obj.calculateMKAverage() << endl; // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
    obj.addElement(85406);
    obj.addElement(49757);  // 当前元素为 [3,1,10]
    cout << obj.calculateMKAverage() << endl; // 最后 3 个元素为 [3,1,10]
    // 删除最小以及最大的 1 个元素后，容器为 [3]
    // [3] 的平均值等于 3/1 = 3 ，故返回 3
    obj.addElement(27520);        // 当前元素为 [3,1,10,5]
    obj.addElement(12303);        // 当前元素为 [3,1,10,5,5]
            // 当前元素为 [3,1,10,5,5,5]
    cout << obj.calculateMKAverage() << endl; // 最后 3 个元素为 [5,5,5]
    obj.addElement(63945);
    // 删除最小以及最大的 1 个元素后，容器为 [5]
    // [5] 的平均值等于 5/1 = 5 ，故返回 5
    return 0;
}