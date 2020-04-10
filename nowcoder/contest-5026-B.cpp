#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t, a, b, day;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        day = 0;
        while(a != b && a != 0)
        {
            if(a > b)//swap 使 a 较小
                a^=b^=a^=b;
            if((a<<1) <= b) //a*2 <= b 则使用魔法翻倍
            {
                day++;
                a <<= 1;
            }
            else    //否则 都吃掉一个
            {
                a--;
                b--;
                day++;
            }
        }
        day += a;
        cout << day << endl;
    }
    return 0;
}