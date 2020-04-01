#include <bits/stdc++.h>
using namespace std;

const int n = 8;
int a[n+1]={0,1,2,3,4,5,6,7,8}, c[n+1] = {0}; //对应原数组和树状数组
int sum1[n+1] = {0}, sum2[n+1] = {0};
int lowbit(int x){
    return x&(-x);
}
//-------单点修改----------
void update(int i, int delta){    //在i位置加上delta（单点）
    while(i <= n){
        c[i] += delta;
        i += lowbit(i);
    }
}

int query(int i){    //求A[1],A[2],...A[i]的和
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

//------区间修改-------
void update1(int i, int delta){    //在i位置加上delta（区间修改）
    while(i <= n){
        sum1[i] += delta;
        sum2[i] += delta*i;
        i += lowbit(i);
    }
}
void update_range(int l, int r, int delta)    //给区间加上delta
{
    update1(l, delta);
    update1(r+1, -delta);
}

int query_p(int i){
    int res = 0;
    while(i > 0){
        res += (i+1)*sum1[i] - sum2[i];
        i -= lowbit(i);
    }
    return res;
}
int query_range(int l, int r)
{
    return query_p(r)-query_p(l-1);
}
int main(){
    //单点修改
    cout << "单点修改，单点查询" << endl;
    for(int i = 1; i < 9; ++i)
        update(i,a[i]);//读取原数据，插入树状数组
    cout << query(3) << endl;//获取前3个数的和
    cout << query(8) << endl;
    update(3,2);
    cout << query(3) << endl;
    cout << query(8) << endl;
    cout << query(4)-query(2) << endl;//获取A[3],A[4]的区间和
    cout << "区间修改，单点查询" << endl;
    for(int i = 1; i < 9; ++i)
        update1(i,a[i]-a[i-1]);//读取原数据差值，插入树状数组
    cout << query_p(3)+ << endl;//获取前3个数的和
    cout << query_p(8) << endl;
    update_range(3,4,2);
    cout << query_p(3) << endl;
    cout << query_p(8) << endl;
    cout << query_range(3,4) << endl;//获取A[3],A[4]的区间和
    return 0;
}