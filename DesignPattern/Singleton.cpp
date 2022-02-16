#include <iostream>

using namespace std;

/*
	�̱��� ����:		���� �� ���� �ν��Ͻ��� ������ ����ϱ����� ������ ����

	�� ���°�?:		��ü ������ �ڿ��� �����ϴ� ���ӸŴ��� Ŭ������ ��� �ϳ��� �ν��Ͻ��� �����ؾ��Ѵ�.
					���ӸŴ����� �ν��Ͻ��� ������ ������ �� �ִٸ�, ��ü ������ �帧�� ���� ���� �Ŵ����� ��� ���̵ǰ�
					���ǹ��ϰ� �򰥸� �� �ִ�.
					���� ���� �ν��Ͻ��̱� ������ �ٸ� Ŭ������� ������ ����.

	������:			���������� �ٷ�� ������ ������� ��������� �浹�� �Ͼ �� �ִ�.
					������ �ʱ�ȭ ����� �̿��� ��Ÿ�ӿ��� �ʱ�ȭ�� �̷������. ������ ���� �������� 
					���ӿ�����ŭ�� �ʱ�ȭ�Ǵ� �޸𸮳� ���ҽ��� ����� ���� �÷��̵��� ���������� ������ ����� �Ͼ ���ִ�.
					��ü���� ���յ�(Ŀ�ø�)�� ������ ���� �׽�Ʈ�� �����丵 �۾��� ������� �� �ִ�. (loc �����̳� ��� ����)
*/

/*
	��ü:			����Ʈ��� ������ ���
	�ν��Ͻ�:		����Ʈ��� ������ ��ü
	������ �ʱ�ȭ:	�ʿ��� �������� �ʱ�ȭ�� ������Ű�� �� 
					->	���� ��ü�� ��� ������ �Ҹ������ ��Ȯ�� �����������ʴ�. ����, A ��� ���� ��ü��
						B ��� ������ü�� �����Ϸ��� �� B�� ��ó �������� �ʾ��� ��찡 ���� ���������� �����ؾ��Ѵ�.
*/

class CSingleton
{
private:
	int Data{};
	static CSingleton* Instance;
private:
	CSingleton() { cout << "Singleton()" << endl; }	// �ܺο��� ��ü�� ������ �� ������ private�� �����ڸ� ������
	~CSingleton() { cout << "~Singleton()" << endl; }// �ܺο��� ������ delete�ϴ� ���� ����
public:
	static CSingleton* GetInstance()
	{
		if (!Instance) Instance = new CSingleton{};	// ������ �ʱ�ȭ, ������ �ѹ��� ȣ��
		return Instance;
	}
	int GetData() const { return Data; }
	void SetData(int param) { Data = param; }
};

CSingleton* CSingleton::Instance{};

int main()
{
	//	���� ������ ������ ����� �ʿ�� ������, �� ������ ���� �ν��Ͻ��� �����ٴ� ���� �����ֱ� �����̴�.
	CSingleton* Inst1{ CSingleton::GetInstance() };
	CSingleton* Inst2{ CSingleton::GetInstance() };

	Inst1->SetData(10);
	Inst2->SetData(-10);
	cout << Inst1->GetData() << endl;
	cout << Inst2->GetData() << endl;
}