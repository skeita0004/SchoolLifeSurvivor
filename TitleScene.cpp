#include "TitleScene.h"
#include "Input.h"

TitleScene::TitleScene(GameObject* _parent) :
    GameObject(_parent, "TitleScene"),
    pSceneManager_(nullptr)
{
}

void TitleScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
}

void TitleScene::Update()
{
    if (Input::IsKeyDown(DIK_P))
    {
        pSceneManager_->ChangeScene(SCENE_ID_PLAY);
    }
    if (Input::IsKeyDown(DIK_G))
    {
        pSceneManager_->ChangeScene(SCENE_ID_GUIDE);
    }

}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
