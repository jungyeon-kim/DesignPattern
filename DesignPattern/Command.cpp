#include <iostream>

using namespace std;

/*
    명령 패턴:  함수를 객체화시켜 사용하는 패턴

    장점: 커플링이 낮아진다.
    단점: 명령이 추가될 때마다 클래스를 추가해야하므로 잡다해질 수 있다.
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