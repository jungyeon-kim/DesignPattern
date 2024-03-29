#include <iostream>

using namespace std;

/*
    MVC 패턴: Model + View + Controller로 나눠 코드를 관리하는 패턴 (사용자의 액션은 Controller에서 처리한다.)

    장점: 간단하게 데이터와 UI를 나눠 관리할 수 있다.
    단점: Model과 View 사이에 의존성이 높다.
*/

class Model
{
public:
    float Data = 0.0f;
};

class View
{
public:
    void RefreshUI(float InValue)
    {
        cout << InValue << endl;
    }
};

class Controller
{
private:
    Model Model;
    View View;
public:
    void OnUserScroll(float const InScrollOffset)
    {
        Model.Data = InScrollOffset;
        View.RefreshUI(Model.Data);
    }
};

int main()
{
    Controller Controller;

    Controller.OnUserScroll(10.0f);
    Controller.OnUserScroll(20.0f);
}
