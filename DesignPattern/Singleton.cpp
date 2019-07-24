#include <iostream>

using namespace std;

/*
	�̱��� ����:	���� �� ���� �ν��Ͻ��� ������ ����ϱ����� ������ ����

	�� ���°�?:		��ü ������ �ڿ��� �����ϴ� ���ӸŴ��� Ŭ������ ��� �ϳ��� �ν��Ͻ��� �����ؾ��Ѵ�.
					���ӸŴ����� �ν��Ͻ��� ������ ������ �� �ִٸ�, ��ü ������ �帧�� ���� ���� �Ŵ����� ��� ���̵ǰ�
					���ǹ��ϰ� �򰥸� �� �ִ�.
					���� ���� �ν��Ͻ��̱� ������ �ٸ� Ŭ������� ������ ����.

	������:			���������� �ٷ�� ������ ������� ��������� �浹�� �Ͼ �� �ִ�.
					������ �ʱ�ȭ ����� �̿��� ��Ÿ�ӿ��� �ʱ�ȭ�� �̷������. ������ ���� �������� 
					���ӿ�����ŭ�� �ʱ�ȭ�Ǵ� �޸𸮳� ���ҽ��� ����� ���� �÷��̵��� ���������� ������ ����� �Ͼ Ȯ���� ����.
*/

/*
	��ü:			����Ʈ��� ������ ���
	�ν��Ͻ�:		����Ʈ��� ������ ��ü
	������ �ʱ�ȭ:	�ʿ��� �������� �ʱ�ȭ�� ������Ű�� �� 
					->	���� ��ü�� ��� ������ �Ҹ������ ��Ȯ�� �����������ʴ�. ����, A ��� ���� ��ü��
						B ��� ������ü�� �����Ϸ��� �� B�� ��ó �������� �ʾ��� ��찡 ���� ���������� �����ؾ��Ѵ�.
*/

class Singleton
{
private:
	int data{};
	static Singleton* instance;
private:
	Singleton() { cout << "Singleton()" << endl; }	// �ܺο��� ��ü�� ������ �� ������ private�� �����ڸ� ������
	~Singleton() { cout << "~Singleton()" << endl; }// �ܺο��� ������ delete�ϴ� ���� ����
public:
	static Singleton* getInstance()
	{
		if (!instance) instance = new Singleton{};	// ������ �ʱ�ȭ, ������ �ѹ��� ȣ��
		return instance;
	}
	int getData() const { return data; }
	void setData(int param) { data = param; }
};

Singleton* Singleton::instance = nullptr;

int main()
{
	//	���� ������ ������ ����� �ʿ�� ������, �� ������ ���� �ν��Ͻ��� �����ٴ� ���� �����ֱ� �����̴�.
	Singleton* inst1{ Singleton::getInstance() };
	Singleton* inst2{ Singleton::getInstance() };

	inst1->setData(10);
	inst2->setData(-10);
	cout << inst1->getData() << endl;
	cout << inst2->getData() << endl;
}