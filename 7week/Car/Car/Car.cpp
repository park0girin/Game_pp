#include <iostream>

using namespace std;

class MobilePhone
{
public:
    MobilePhone()
    {
        cout << "MobilePhone을 생성합니다\n" << endl;
    }
    ~MobilePhone()
    {
        cout << "MobilePhone을 소멸시킵니다\n" << endl;
    }

    void TurnOn()
    {
        cout << "MobilePhone을 켭니다\n" << endl;
    }
    void TurnOff()
    {
        cout << "MobilePhone을 끕니다\n" << endl;
    }
};

class IPhone :public MobilePhone
{
public:
    IPhone()
    {
        cout << "IPhone을 생성합니다\n" << endl;
    }
    ~IPhone()
    {
        cout << "IPhone을 소멸시킵니다\n" << endl;
    }

    void ApplePay()
    {
        cout << "ApplePay" << endl;
    }
    void Siri()
    {
        cout << "Siri" << endl;
    }
};

class Galaxy :public MobilePhone
{
public:
    Galaxy()
    {
        cout << "Galaxy을 생성합니다\n" << endl;
    }
    ~Galaxy()
    {
        cout << "Galaxy을 소멸시킵니다\n" << endl;
    }

    void SamsungPay()
    {
        cout << "SamsungPay" << endl;
    }
    void Bixby()
    {
        cout << "Bixby" << endl;
    }
};

int main()
{
    cout << "MobilePhone에 대한 예제입니다.\n" << endl;

    IPhone *i = new IPhone();
    Galaxy g;

    cout << endl;
    i->Siri();
    g.Bixby();

    cout << endl;
    delete(i);
    
}
