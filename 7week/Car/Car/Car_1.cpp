#include <iostream>

using namespace std;

class MobilePhone
{
public:
    MobilePhone()
    {
        cout << "MobilePhone�� �����մϴ�\n" << endl;
    }
    ~MobilePhone()
    {
        cout << "MobilePhone�� �Ҹ��ŵ�ϴ�\n" << endl;
    }

    void TurnOn()
    {
        cout << "MobilePhone�� �մϴ�\n" << endl;
    }
    void TurnOff()
    {
        cout << "MobilePhone�� ���ϴ�\n" << endl;
    }
};

class IPhone :public MobilePhone
{
public:
    IPhone()
    {
        cout << "IPhone�� �����մϴ�\n" << endl;
    }
    ~IPhone()
    {
        cout << "IPhone�� �Ҹ��ŵ�ϴ�\n" << endl;
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
        cout << "��\n" << endl;
    }
};

class Galaxy :public MobilePhone
{
public:
    Galaxy()
    {
        cout << "Galaxy�� �����մϴ�\n" << endl;
    }
    ~Galaxy()
    {
        cout << "Galaxy�� �Ҹ��ŵ�ϴ�\n" << endl;
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
        cout << "�Ｚ\n" << endl;
    }
};

int main()
{
    cout << "MobilePhone�� ���� �����Դϴ�.\n" << endl;
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
