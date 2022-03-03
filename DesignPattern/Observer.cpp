#include <iostream>
#include <functional>

using namespace std;

/*
    ������ ����)
    ��ü�� ��ȭ�� �Ͼ�� ��, �ٸ� ��ü�� �̸� �˾������� ������ �� �ְ� �ϴ� ����

    ����)
    1. ������ �л��Ű�� �ʰ� �� ���� ��� ������������ ���ȴ�.
    2. ��ü���� Ŀ�ø��� ��������.

    Ư�̻���)
    ���������� ������ �����̶� ���� ������(Observer), �ǰ�����(Subject) �������̽��� �����
    ������� ����ϴ� ���� �����������, ���ó����� ��������Ʈ, �Լ������Ϳ� ���� ���� ��ü���� �ִ�.
*/

enum class Event { Kill_Monster, Find_Spot };

// �̱������� ��ü�ϴ� �͵� �������
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