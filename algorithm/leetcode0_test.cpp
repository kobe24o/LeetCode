/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10)
            return n;
        int count = 9, i = 2, num = 9;
        while(count+9*pow(10,i-1)*i <= n)
        {
            count += 9*pow(10,i-1)*i;
            num += 9*pow(10,i-1);
            i++;
        }
        n -= count;
        if(n%i != 0)
            return fd(num+n/i+1,n%i);
        return fd(num+n/i,i);
    }

    int fd(int num, int n)
    {
        int i = int(1e9);
        int bit;
        while(num/i == 0)
            i /= 10;
        while(n--)
        {
            bit = num/i;
            num -= bit*i;
            i /= 10;
        }
        return bit;
    }
};
class People
{
public:
    string name;
    int id;
    People(string n, int i):name(n),id(i){}
    bool operator==(const People& a)
    {
        return id == a.id && name==a.name;
    }
    bool operator<( const People& a)
    {
        if(id == a.id)
            return name < a.name;
        return id < a.id;
    }
} ;

bool operator==(const People& a, const People& b)
{
    return a.id == b.id && a.name==b.name;
}

bool operator<(const People &a, const People& b)
{
    if(a.id == b.id)
        return a.name < b.name;
    return a.id < b.id;
}

int main()
{
     Student s(001,"Michael","man","19XX-XX-XX");
     s.show();
     return 0;
}