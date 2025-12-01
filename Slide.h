#pragma once
#include "Engine/GameObject.h"
#include <vector>

class SceneManager;
class BackGround;

class Slide : public GameObject
{
public:
    Slide(GameObject* _parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

private:
    BackGround* pBackGround_;
    SceneManager* pSceneManager_;
    std::vector<std::string> imagePaths_;
};