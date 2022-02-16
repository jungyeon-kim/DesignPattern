#include <iostream>
#include <string>

using namespace std;

/*
    �淮 ����:  ����� �����͸� ���� ���� ���ϰ�ü�� ũ�⸦ ���̴� ����

    ����: ����� ��ü�� ������ ���������ʰ� �����ϹǷ� �޸𸮸� ������ �� ����
*/

class CBulletBase
{
private:
    // ������ �� �� ��������� ����� �����Ͷ�� ����
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
    // �����ϱ� ���� ����� ������
    CBulletBase* BulletBase = new CBulletBase(10.0f, 5.0f, "BulletTexture");

    // ����� �����͸� Ȱ���� ������ �ҷ� ����
    CBullet* Bullet1 = new CBullet(BulletBase, 10.0f, 0.0f);
    CBullet* Bullet2 = new CBullet(BulletBase, 7.0f, 5.0f);
    CBullet* Bullet3 = new CBullet(BulletBase, 20.0f, 15.0f);

    delete Bullet3;
    delete Bullet2;
    delete Bullet1;

    delete BulletBase;
}