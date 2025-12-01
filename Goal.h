#pragma once
#include "Engine/GameObject.h"

class SceneManager;

class Goal : public GameObject
{
public:
    Goal(GameObject* _parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

private:
    void OnCollision(GameObject* _pTarget) override;

    int hModel_;
    SceneManager* pSceneManager_;
    bool isGoaled_;
};