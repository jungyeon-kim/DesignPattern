#include <iostream>

using namespace std;

/*
    ��� ����:  �Լ��� ��üȭ���� ����ϴ� ����

    ����: Ŀ�ø��� ��������.
    ����: ����� �߰��� ������ Ŭ������ �߰��ؾ��ϹǷ� ������� �� �ִ�.
*/

class CCommand abstract
{
    CCommand() = default;
    virtual ~CCommand() = default;

    virtual void Execute() = 0;
    virtual void Undo() = 0;
};

class CInputController
{
    
};

int main()
{
}