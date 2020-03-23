/**
 * @Description: 研究递归下栈溢出问题
 * @Author: michael ming
 * @Date: 2020/3/23 18:08
 * @Modified by: 
 * @Website: https://michael.blog.csdn.net/
 */

#include <iostream>
using namespace std;

void dfs(int i, int j, int a, int b,int c) {
    // 依次去掉d c b a z y x，观察一下：段错误的深度 && k变量每深入一层调用，其地址的相对偏移量
    int k = 0, z = 0, x = 0, y = 0;
    cout << "&k = " << &k << endl;
    cout << "i = " << i << endl;
    i = i+1;
    dfs(i, j, a, b,c);
}
void dfs(int i) {
    // 依次去掉d c b a z y x，观察一下：段错误的深度 && k变量每深入一层调用，其地址的相对偏移量
    int k = 0;
    cout << "&k = " << &k << endl;
    cout << "i = " << i << endl;
    i = i+1;
    dfs(i);
}
bool isok(int &a, int &b, int &c, int &d)
{
    return true;
}
void dfs(int i, int j) {
    // 依次去掉d c b a z y x，观察一下：段错误的深度 && k变量每深入一层调用，其地址的相对偏移量
    int k = 0, z = 0, x = 0, y = 0;
    cout << "&k = " << &k << endl;
    cout << "i = " << i << endl;
    i = i+1;
    if(isok(k,z,x,y))
        dfs(i);
}



int main() {
    int i = 0;
    int j = 0;
    int a = 0, b = 0, c = 0;
    cout << "size of int& " << sizeof(int&) << endl;
    cout << "size of int " << sizeof(int) << endl;
//    dfs(i, j, a, b,c);
//    dfs(i);
    dfs(i,j);
}
