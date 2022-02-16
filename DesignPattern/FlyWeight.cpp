#include <iostream>
#include <string>

using namespace std;

/*
    경량 패턴:  공통된 데이터를 따로 묶어 단일객체의 크기를 줄이는 패턴

    장점: 공통된 객체를 여러번 생성하지않고 재사용하므로 메모리를 절약할 수 있음
*/

class CBulletBase
{
private:
    // 간단히 이 세 멤버변수가 공통된 데이터라고 가정
    float Damage = 0.0f;
    float Speed = 0.0f;
    string Texture = string();
public:
    CBulletBase() = default;
    CBulletBase(float InDamage, float InSpeed, const string& InTexture)
        : Damage(InDamage), Speed(InSpeed), Texture(InTexture) {}
    ~CBulletBase() = default;
};

class CBullet
{
private:
    CBulletBase* BulletBase = nullptr;
    float PosX = 0.0f, PosY = 0.0f;
public:
    CBullet() = default;
    CBullet(CBulletBase* InBulletBase, float InPosX, float InPosY)
        : BulletBase(InBulletBase), PosX(InPosX), PosY(InPosY) {}
    ~CBullet() = default;
};

int main()
{
    // 재사용하기 위한 공통된 데이터
    CBulletBase* BulletBase = new CBulletBase(10.0f, 5.0f, "BulletTexture");

    // 공통된 데이터를 활용해 각각의 불렛 생성
    CBullet* Bullet1 = new CBullet(BulletBase, 10.0f, 0.0f);
    CBullet* Bullet2 = new CBullet(BulletBase, 7.0f, 5.0f);
    CBullet* Bullet3 = new CBullet(BulletBase, 20.0f, 15.0f);

    delete Bullet3;
    delete Bullet2;
    delete Bullet1;

    delete BulletBase;
}