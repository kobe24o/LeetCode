#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
using namespace std;
#include <string>     // std::string, std::stoi


#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
using namespace std;
#include <string>     // std::string, std::stoi


#include<iostream>
#include<string>
using namespace std;

const int n = 3;
class Patient
{
private:
    int m_Id;
    string m_Name;
    double* m_temperature;//指向包含早中晚3个体温值的堆区数组
public:
    Patient(int = 0, string = "#", double*t = NULL);
    Patient(const Patient& p);
    ~Patient();

    //此处添加友元函数4
    friend ostream& operator<<(ostream& out, Patient& p);
};
Patient::Patient(int Id, string Name, double* temperature)//此处添加构造函数，析构函数定义2
{
    m_Id = Id;
    m_Name = Name;
    if(temperature) {
        this->m_temperature = new double[3];
        for (int i = 0; i < 3; i++)
            this->m_temperature[i] = temperature[i];
    }
}
Patient::Patient(const Patient& p)//此处添加深复制构造函数3
{
    m_Id = p.m_Id;
    m_Name = p.m_Name;
    if(p.m_temperature) {
        this->m_temperature = new double[3];
        for (int i = 0; i < 3; i++)
            this->m_temperature[i] = p.m_temperature[i];
    }
}
Patient::~Patient()
{
    if (m_temperature != NULL)
    {
        delete[] m_temperature;
    }
}
//友元函数
ostream& operator<<(ostream& out, Patient& p)
{
    out << "Id:" << p.m_Id << "  名字:" << p.m_Name<<" "<<endl;
    return out;
}
int main()
{
    double temp[n] = { 37.5, 38, 37.8 };
    int id = 0;
    Patient pat1(1, "Rose", temp), pat2(2, "Tom"), pat3(pat1);

    cout << pat1 << pat2 << pat3;

    //读出二进制文件中的内容并输出到显示器6
    system("pause");
    return 0;
}


