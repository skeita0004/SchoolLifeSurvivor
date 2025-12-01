#pragma once
#include "Engine/GameObject.h"

class Item : public GameObject
{
public:
    Item(GameObject* _parent);

    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;

private:
    void OnCollision(GameObject* _pTarget) override;
    int hModel_;
    bool isObtained_;
};