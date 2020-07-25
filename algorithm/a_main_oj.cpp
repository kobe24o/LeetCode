#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
using namespace std;
#include <string>     // std::string, std::stoi


int main ()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int test, count;
    double m, n, p;
    cin >> test;
    while(test--)
    {
        cin >> n >> m >> p ;
        if(m*(100-p)/100 > ceil((m*p/100)))
            count = ceil((n-(m*(100-p)/100))/ceil((m*p/100)));
        else
            count = (n-(m*(100-p)/100))/ceil((m*p/100));
        printf("%d\n",count);
    }
    return 0;
}