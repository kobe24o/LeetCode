#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
#include <string>     // std::string, std::stoi
#include <map>
#include<stack>
# include<queue>
#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

class Solution {
    int local = 0, global = 0;
    vector<int> tmp;
public:
    bool isIdealPermutation(vector<int>& A) {
        if(A.size() <= 1) return true;
        for(int i = 0; i < A.size()-1; ++i)
            if(A[i] > A[i+1])
                local++;
        tmp.resize(A.size());
        mergesort(A, 0, A.size()-1);
        cout << global << endl;
        return local == global;
    }
    void mergesort(vector<int>& A, int l, int r)
    {
        if(l >= r) return;
        int mid = (l+r)/2;
        mergesort(A, l, mid-1);
        mergesort(A, mid, r);
        int i = l, j = mid, k = 0;
        while(i < mid && j <= r)
        {
            if(A[i] <= A[j])
                tmp[k++] = A[i++];
            else//前面没出队的比后面已经出来的都大
            {
                tmp[k++] = A[j++];
                global += mid-i;
            }
        }
        while(i < mid)
        {
            tmp[k++] = A[i++];
        }
        while(j <= r)
            tmp[k++] = A[j++];
        k = 0; i = l;
        while(i <= r)
            A[i++] = tmp[k++];
    }
};

int main()
{
    vector<int> l = {6,3,5};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{15,96},{36,2}};
     Solution s;
    string str = "bacbdab";
     cout << s.isIdealPermutation(l) <<endl;
    cout << "hello" << endl;
    system("pause");
    return 0;
}


