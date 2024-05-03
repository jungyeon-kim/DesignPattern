#include <iostream>

using namespace std;

/*
    파사드 패턴: 여러 서브 시스템들을 숨기고 하나의 인터페이스로 제공해주는 패턴

    장점: 사용처와 서브 시스템 간의 커플링이 감소한다.
*/

class SubsystemA
{
public:
    void DoTask()
    {
        cout << "SubsystemA" << endl;
    }
};

class SubsystemB
{
public:
    void DoTask()
    {
        cout << "SubsystemB" << endl;
    }
};

class SubsystemC
{
public:
    void DoTask()
    {
        cout << "SubsystemC" << endl;
    }
};

class Facade
{
private:
    SubsystemA A;
    SubsystemB B;
    SubsystemC C;
public:
    void DoTask()
    {
        A.DoTask();
        B.DoTask();
        C.DoTask();
    }
};

int main()
{
    Facade F;

    F.DoTask();
}
