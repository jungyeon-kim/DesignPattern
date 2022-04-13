#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

/*
    상태 패턴)
    객체에 "상태"라는 추상적인 개념을 도입시킨 패턴

    특징)
    1. 가질 수 있는 상태가 한정된다. (이동하는, 서있는, 엎드려있는, 떠있는 등)
    2. 기본적으로 하나의 상태만 가질 수 있다.
    3. 입력 or 이벤트가 전달되어 기존 상태가 다음 상태로 전이될 수 있다.
    4. 상태는 주로 열거형 or 객체로 구현하며, 유한상태기계(FSM)이 좋은 예시이다.

    장점)
    1. 예외처리같은 분기로직을 간소화시켜 유지보수성이 올라간다.
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