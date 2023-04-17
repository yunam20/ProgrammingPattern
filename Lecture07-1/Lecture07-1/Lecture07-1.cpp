#include <iostream>

using namespace std;

class MobilePhone
{
public:
	MobilePhone()
	{
		cout << "MoblinePhone을 생성합니다" << endl;
	}
	virtual ~MobilePhone()
	{
		cout << "MoblinePhone을 소멸시킵니다" << endl;
	}

	void virtual TurnON() //virtual = 가상화, 선언만 함. 자식이 오버라이드함
	{
		cout << "MobilePhone을 켭니다." << endl;
	}
	void virtual TurnOff()
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

	void TurnON()
	{
		cout << "IPhone을 켭니다." << endl;
	}
	void TurnOff()
	{
		cout << "IPhone을 끕니다." << endl;
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

	void TurnON()
	{
		cout << "Galaxy을 켭니다." << endl;
	}
	void TurnOff()
	{
		cout << "Galaxy을 끕니다." << endl;
	}
};


void main()
{
	cout << "프로그래밍패턴수업 클래스기초이해\n" << endl;

	MobilePhone** mp = new MobilePhone* [2];
	mp[0] = new IPhone();
	mp[1] = new Galaxy();
	
	for (size_t i = 0; i < 2; i++)
	{
		mp[i]->TurnON();
		delete(mp[i]);
	}
	//delete(mp);
	//delete(i);
	/*mp를 지운 뒤 i을 지우려고 하면 i는 IPhone = 부모에게서
	상속받으므로 이미 반환된 공간을 다시 삭제하려고 하게됨
	*/
}