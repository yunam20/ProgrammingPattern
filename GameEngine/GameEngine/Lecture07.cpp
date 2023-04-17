#include <iostream>

using namespace std;

class MobilePhone
{
public:
	MobilePhone()
	{
		cout << "MoblinePhone을 생성합니다" << endl;
	}
	~MobilePhone()
	{
		cout << "MoblinePhone을 소멸시킵니다" << endl;
	}

	void TurnON()
	{
		cout << "MobilePhone을 켭니다." << endl;
	}
	void TurnOff()
	{
		cout << "MobliePhone을 끕니다." << endl;
	}
};

class IPhone : public MobilePhone
{
public:
	IPhone()
	{
		cout << "IPhone을 생성합니다" << endl;
	}
	~IPhone()
	{
		cout << "IPhone을 소멸시킵니다" << endl;
	}

	void ApplePay()
	{
		cout << "ApplePay: 유한대학교에 등록금 289646436761원이 결제되었습니다." << endl;
	}
	void Siri()
	{
		cout << "Siri: 당신은 사람취급 받을 자격이 없습니다." << endl;
	}
};

class Galaxy : public MobilePhone
{
public:
	Galaxy()
	{
		cout << "Galaxy을 생성합니다" << endl;
	}
	~Galaxy()
	{
		cout << "Galaxy을 소멸시킵니다" << endl;
	}

	void SamsungPay()
	{
		cout << "SamsungPay: 유한대학교에 등록금 289646436761원이 결제되었습니다." << endl;
	}
	void Bixby()
	{
		cout << "Bixby: 이히히 이 수업 망해라" << endl;
	}
};


void main()
{
	cout << "프로그래밍패턴수업 클래스기초이해\n" << endl;

	IPhone *i = new IPhone(); //new = 동적 할당, 포인터로 주소값을 지정하고 주소값에 생성
	Galaxy g; //정적 할당, new와는 달리 함수가 끝나면 자동으로 delete됨

	cout << endl;
	i->Siri(); //포인터는 -> 사용. C에서도 배움
	g.Bixby();

	cout << endl;
	delete(i);
}