#include <iostream>

using namespace std;

/*
    ��� ����:  �Լ��� ��üȭ���� ����ϴ� ����

    ����: Ŀ�ø��� ��������.
    ����: ����� �߰��� ������ Ŭ������ �߰��ؾ��ϹǷ� ������� �� �ִ�.
*/

class Command abstract
{
    Command() = default;
    virtual ~Command() = default;

    virtual void Execute() = 0;
    virtual void Undo() = 0;
};

class InputController
{
    
};

int main()
{
}