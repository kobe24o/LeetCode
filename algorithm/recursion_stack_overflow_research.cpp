/**
 * @Description: 研究递归下栈溢出问题
 * @Author: michael ming
 * @Date: 2020/3/23 18:08
 * @Modified by: 
 * @Website: https://michael.blog.csdn.net/
 */

#include <iostream>
using namespace std;

class memory1
{
    int id;
    char a[1280];
    char b;
};
class memory2
{
    char a;
    int id;
    char b;
};
class memory3
{
    char a;
    char b;
    int id;
};
bool isok(int a, int b, int c, int d,int e)
{
    if(a)
        ;
    return true;
}
void dfs(memory1 &m1, int &i, int &j, int &a, int &b,int &c,int &d, int &e,int &f,int &g,int &h) {
    // 依次去掉d c b a z y x，观察一下：段错误的深度 && k变量每深入一层调用，其地址的相对偏移量
    int k = 0;
    cout << "&k = " << &k << endl;
    cout << "i = " << i << endl;
    i = i+1;
//    if(isok(k,a,b,c,d))
    dfs(m1, i, j, a, b,c,d,e,f,g,h);
}
void dfs(int &i) {
    // 依次去掉d c b a z y x，观察一下：段错误的深度 && k变量每深入一层调用，其地址的相对偏移量
    int k = 0;
    cout << "&k = " << &k << endl;
    cout << "i = " << i << endl;
    i = i+1;
    dfs(i);
}

void dfs(int i, int j) {
    // 依次去掉d c b a z y x，观察一下：段错误的深度 && k变量每深入一层调用，其地址的相对偏移量
    int k = 0;
    cout << "&k = " << &k << endl;
    cout << "i = " << i << endl;
    i = i+1;
    dfs(i,j);
}


int main() {
    int i = 0;
    int j = 0;
    int a = 0, b = 0, c = 0,d=0,e=0,f=0,g=0,h=0,l=0;
    memory1 m1;
    cout << "size of int& " << sizeof(int&) << endl;
    cout << "size of int " << sizeof(int) << endl;
    cout << "size of char " << sizeof(char) << endl;
    cout << "size of memory1 " << sizeof(m1) << endl;
    cout << "size of memory1& " << sizeof(&m1) << endl;
    cout << "size of Pointer " << sizeof(int*) << endl;
    cout << "size of memory2 " << sizeof(memory2) << endl;
    cout << "size of memory3 " << sizeof(memory3) << endl;
//    dfs(m1,i, j, a, b,c,d,e,f,g,h);
//    dfs(i);
    dfs(i,j);
//    int x = 1;
//    int y = 2;
//    int &a1 = x;
//    printf("&x=%x,&y=%x,&a1=%x,a1=%x\n",&x,&y,&y-1,*(&y-1));
    return 0;
}
