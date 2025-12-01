#pragma once
#include "Engine/GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(GameObject* _parent);

    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;

private:
    void OnCollision(GameObject* _pTarget) override;

    int hModel_;
    bool isHit_;
    float animTime_;
    XMFLOAT3 basePos_;
};