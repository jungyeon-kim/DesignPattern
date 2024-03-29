#include <iostream>
#include <vector>

using namespace std;

/*
    MVC 패턴: Model + View + Controller로 나눠 코드를 관리하는 패턴

    순서: UserInput -> Controller -> Model -> Controller -> View

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
