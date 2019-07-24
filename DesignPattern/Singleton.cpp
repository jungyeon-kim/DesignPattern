#include <iostream>

using namespace std;

/*
	싱글턴 패턴:	오직 한 개의 인스턴스를 생성해 사용하기위한 디자인 패턴

	왜 쓰는가?:		전체 게임의 자원을 관리하는 게임매니저 클래스의 경우 하나의 인스턴스만 존재해야한다.
					게임매니저의 인스턴스를 여러개 생성할 수 있다면, 전체 게임의 흐름을 여러 게임 매니저에 담는 셈이되고
					무의미하고 헷갈릴 수 있다.
					또한 전역 인스턴스이기 때문에 다른 클래스들과 공유가 쉽다.

	문제점:			전역변수를 다루기 때문에 디버깅이 힘들어지고 충돌이 일어날 수 있다.
					게으른 초기화 기법을 이용해 런타임에서 초기화가 이루어진다. 문제가 없어 보이지만 
					게임에서만큼은 초기화되는 메모리나 리소스가 방대할 수록 플레이도중 순간적으로 프레임 드랍이 일어날 확률이 높다.
*/

/*
	객체:			소프트웨어에 구현할 대상
	인스턴스:		소프트웨어에 구현된 실체
	게으른 초기화:	필요한 시점까지 초기화를 지연시키는 것 
					->	전역 객체의 경우 생성과 소멸순서가 명확히 정해져있지않다. 따라서, A 라는 전역 객체가
						B 라는 전역객체를 참조하려할 때 B가 미처 생성되지 않았을 경우가 생겨 생성시점을 제어해야한다.
*/

class Singleton
{
private:
	int data{};
	static Singleton* instance;
private:
	Singleton() { cout << "Singleton()" << endl; }	// 외부에서 객체를 생성할 수 없도록 private에 생성자를 재정의
	~Singleton() { cout << "~Singleton()" << endl; }// 외부에서 강제로 delete하는 것을 방지
public:
	static Singleton* getInstance()
	{
		if (!instance) instance = new Singleton{};	// 게으른 초기화, 생성자 한번만 호출
		return instance;
	}
	int getData() const { return data; }
	void setData(int param) { data = param; }
};

Singleton* Singleton::instance = nullptr;

int main()
{
	//	굳이 변수에 복사해 사용할 필요는 없지만, 두 변수가 같은 인스턴스를 가진다는 것을 보여주기 위함이다.
	Singleton* inst1{ Singleton::getInstance() };
	Singleton* inst2{ Singleton::getInstance() };

	inst1->setData(10);
	inst2->setData(-10);
	cout << inst1->getData() << endl;
	cout << inst2->getData() << endl;
}