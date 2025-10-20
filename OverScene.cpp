#include "OverScene.h"
#include "Input.h"

OverScene::OverScene(GameObject* _parent) :
    GameObject(_parent, "OverScene"),
    pSceneManager_(nullptr)
{
}

void OverScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
}

void OverScene::Update()
{
    if (Input::IsKeyDown(DIK_T))
    {
        pSceneManager_->ChangeScene(SCENE_ID_TITLE);
    }

    if (Input::IsKeyDown(DIK_P))
    {
        pSceneManager_->ChangeScene(SCENE_ID_PLAY);
    }
}

void OverScene::Draw()
{
}

void OverScene::Release()
{
}
