#include <iostream>

using namespace std;

class MobilePhone
{
public:
	MobilePhone()
	{
		cout << "MoblinePhone�� �����մϴ�" << endl;
	}
	~MobilePhone()
	{
		cout << "MoblinePhone�� �Ҹ��ŵ�ϴ�" << endl;
	}

	void TurnON()
	{
		cout << "MobilePhone�� �մϴ�." << endl;
	}
	void TurnOff()
	{
		cout << "MobliePhone�� ���ϴ�." << endl;
	}
};

class IPhone : public MobilePhone
{
public:
	IPhone()
	{
		cout << "IPhone�� �����մϴ�" << endl;
	}
	~IPhone()
	{
		cout << "IPhone�� �Ҹ��ŵ�ϴ�" << endl;
	}

	void ApplePay()
	{
		cout << "ApplePay: ���Ѵ��б��� ��ϱ� 289646436761���� �����Ǿ����ϴ�." << endl;
	}
	void Siri()
	{
		cout << "Siri: ����� ������ ���� �ڰ��� �����ϴ�." << endl;
	}
};

class Galaxy : public MobilePhone
{
public:
	Galaxy()
	{
		cout << "Galaxy�� �����մϴ�" << endl;
	}
	~Galaxy()
	{
		cout << "Galaxy�� �Ҹ��ŵ�ϴ�" << endl;
	}

	void SamsungPay()
	{
		cout << "SamsungPay: ���Ѵ��б��� ��ϱ� 289646436761���� �����Ǿ����ϴ�." << endl;
	}
	void Bixby()
	{
		cout << "Bixby: ������ �� ���� ���ض�" << endl;
	}
};


void main()
{
	cout << "���α׷������ϼ��� Ŭ������������\n" << endl;

	IPhone *i = new IPhone(); //new = ���� �Ҵ�, �����ͷ� �ּҰ��� �����ϰ� �ּҰ��� ����
	Galaxy g; //���� �Ҵ�, new�ʹ� �޸� �Լ��� ������ �ڵ����� delete��

	cout << endl;
	i->Siri(); //�����ʹ� -> ���. C������ ���
	g.Bixby();

	cout << endl;
	delete(i);
}