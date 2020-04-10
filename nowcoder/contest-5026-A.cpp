#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t, h, a, H, A;
    cin >> t;
    while(t--)
    {
        while(cin >> h >> a >> H >> A)
        {
            int time = ceil(double(H)/a);//我需要几下打死怪兽，向上取整
            if(time == 1)
            {	//我先手，一次就ko，那可以无数次
                cout << -1 << endl;
                break;
            }
            cout << (h-1)/((time-1)*A) << endl;
            //我保留1滴生命，然后先手，怪兽少打我一次，一只怪兽打我 (time-1)*A 滴生命
        }
    }
    return 0;
}