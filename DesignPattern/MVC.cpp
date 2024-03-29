#include <iostream>
#include <vector>

using namespace std;

/*
    MVC 패턴: Model + View + Controller로 나눠 코드를 관리하는 패턴

    순서: UserInput -> Controller -> Model -> Controller -> View

    장점: 간단하게 데이터와 UI를 나눠 관리할 수 있다.
    단점: Model과 View 사이에 의존성이 높다.

    +)
    단점을 위해 파생된 패턴인 MVP와 MVC가 있다.
    MVP는 Controller 대신 Presenter라는 개념을 도입해 Model과 View의 중간다리 역할로 Model과 View의 의존성을 없앴다. 하지만 View와 Prensenter 간의 의존성이 생기는게 문제다.
    MVVM은 Model View ViewModel의 약자로 Presenter대신 View를 위한 Model, ViewModel의 개념을 도입했다.
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
    vector<View> ViewList{ 5 };
public:
    void OnUserScroll(float const InScrollOffset)
    {
        Model.Data = InScrollOffset;

        for (View& View : ViewList)
        {
            View.RefreshUI(Model.Data); // View와 Model의 커플링 발생
        }
    }
};

int main()
{
    Controller Controller;

    Controller.OnUserScroll(10.0f);
    Controller.OnUserScroll(20.0f);
}
