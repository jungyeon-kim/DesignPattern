#include <iostream>

using namespace std;

/*
    명령 패턴:  함수를 객체화시켜 사용하는 패턴
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