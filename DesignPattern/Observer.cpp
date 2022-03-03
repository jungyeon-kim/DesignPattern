#include <iostream>
#include <functional>

using namespace std;

/*
    관찰자 패턴)
    객체에 변화가 일어났을 때, 다른 객체가 이를 알아차리고 대응할 수 있게 하는 패턴

    장점)
    1. 로직을 분산시키지 않고 한 곳에 모아 유지보수성이 향상된다.
    2. 객체간의 커플링이 낮아진다.

    특이사항)
    보편적으로 관찰자 패턴이라 함은 관찰자(Observer), 피관찰자(Subject) 인터페이스를 만들어
    상속으로 사용하는 것이 통상적이지만, 오늘날에는 딜리게이트, 함수포인터와 같은 좋은 대체제가 있다.
*/

enum class Event { Kill_Monster, Find_Spot };

// 싱글턴으로 대체하는 것도 고려가능
class CAchievement
{
public:
    function<void(CAchievement&, const Event&)> OnAchievement;
protected:
    void DoAchievement(const Event& InEvent)
    {
        switch (InEvent)
        {
        case Event::Kill_Monster:
            cout << "Kill_Monster" << endl;
            break;
        case Event::Find_Spot:
            cout << "Find_Spot" << endl;
            break;
        }
    }
public:
    CAchievement() { OnAchievement = &CAchievement::DoAchievement; }
    ~CAchievement() = default;
};

class CAttack
{
private:
    CAchievement Achieve;
public:
    void KillMonster() { Achieve.OnAchievement(Achieve, Event::Kill_Monster); }
};

class CMove
{
private:
    CAchievement Achieve;
public:
    void FindSpot() { Achieve.OnAchievement(Achieve, Event::Find_Spot); }
};

int main()
{
    CAttack Attack;
    CMove Move;

    Attack.KillMonster();
    Move.FindSpot();
}