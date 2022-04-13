#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

/*
    ���� ����)
    ��ü�� "����"��� �߻����� ������ ���Խ�Ų ����

    Ư¡)
    1. ���� �� �ִ� ���°� �����ȴ�. (�̵��ϴ�, ���ִ�, ������ִ�, ���ִ� ��)
    2. �⺻������ �ϳ��� ���¸� ���� �� �ִ�.
    3. �Է� or �̺�Ʈ�� ���޵Ǿ� ���� ���°� ���� ���·� ���̵� �� �ִ�.
    4. ���´� �ַ� ������ or ��ü�� �����ϸ�, ���ѻ��±��(FSM)�� ���� �����̴�.

    ����)
    1. ����ó������ �б������ ����ȭ���� ������������ �ö󰣴�.
*/

enum class EEvent
{
    Idle,
    Move,
    Jump
};

class CPlayer
{
private:
    unique_ptr<class IState> CurrentState = nullptr;
public:
    CPlayer();
    ~CPlayer() = default;

    void Update(EEvent InEvent);

    void SetState(class IState* InState);
};

class IState abstract
{
public:
    IState() = default;
    virtual ~IState() = default;

    virtual void AcceptEvent(CPlayer* InPlayer, EEvent InEvent) = 0;
};

class CIdleState : public IState
{
public:
    CIdleState() = default;
    virtual ~CIdleState() override = default;
    
    virtual void AcceptEvent(CPlayer* InPlayer, EEvent InEvent) override;
};

class CMoveState : public IState
{
public:
    CMoveState() = default;
    virtual ~CMoveState() override = default;
    
    virtual void AcceptEvent(CPlayer* InPlayer, EEvent InEvent) override;
};

class CJumpState : public IState
{
public:
    CJumpState() = default;
    virtual ~CJumpState() override = default;
    
    virtual void AcceptEvent(CPlayer* InPlayer, EEvent InEvent) override;
};

CPlayer::CPlayer()
{
    CurrentState = make_unique<CIdleState>();
}

void CPlayer::Update(EEvent InEvent)
{
    CurrentState->AcceptEvent(this, InEvent);
}

void CPlayer::SetState(class IState* InState)
{
    CurrentState.reset(InState);
}

void CIdleState::AcceptEvent(CPlayer* InPlayer, EEvent InEvent)
{
    switch (InEvent)
    {
    case EEvent::Move:
        cout << "Idle -> Move" << endl;
        InPlayer->SetState(new CMoveState);
        break;
    case EEvent::Jump:
        cout << "Idle -> Jump" << endl;
        InPlayer->SetState(new CJumpState);
        break;
    }
}

void CMoveState::AcceptEvent(CPlayer* InPlayer, EEvent InEvent)
{
    switch (InEvent)
    {
    case EEvent::Idle:
        cout << "Move -> Idle" << endl;
        InPlayer->SetState(new CIdleState);
        break;
    case EEvent::Jump:
        cout << "Move -> Jump" << endl;
        InPlayer->SetState(new CJumpState);
        break;
    }
}

void CJumpState::AcceptEvent(CPlayer* InPlayer, EEvent InEvent)
{
    switch (InEvent)
    {
    case EEvent::Idle:
        cout << "Jump -> Idle" << endl;
        InPlayer->SetState(new CIdleState);
        break;
    case EEvent::Move:
        cout << "Can not move on jump state." << endl;
        break;
    }
}

int main()
{
    unique_ptr<CPlayer> Player = make_unique<CPlayer>();
    int Input = 0;

    while(true)
    {
        cin >> Input;

        switch (Input)
        {
        case 1:
            Player->Update(EEvent::Idle);
            break;
        case 2:
            Player->Update(EEvent::Move);
            break;
        case 3:
            Player->Update(EEvent::Jump);
            break;
        }
    }
}