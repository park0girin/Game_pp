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

    void TurnOn()
    {
        cout << "◐\n" << endl;
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
    void TurnOn()
    {
        cout << "삼성\n" << endl;
    }
};

int main()
{
    cout << "MobilePhone에 대한 예제입니다.\n" << endl;
    cout << endl;
    
    MobilePhone** mp = new MobilePhone * [2];
    mp[0] = new IPhone();
    mp[1] = new Galaxy();

    for (size_t i = 0; i < 2; i++)
    {
        mp[i]->TurnOn();
        delete(mp[i]);
    }
}
