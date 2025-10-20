#include "PlayScene.h"
#include "Input.h"
#include "Sprite.h"

PlayScene::PlayScene(GameObject* _parent):
    GameObject(_parent, "PlayScene"),
    pSceneManager_(nullptr)
{
}

void PlayScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
}

void PlayScene::Update()
{
    if (Input::IsKeyDown(DIK_O))
    {
        pSceneManager_->ChangeScene(SCENE_ID_OVER);
    }

    if (Input::IsKeyDown(DIK_C))
    {
        pSceneManager_->ChangeScene(SCENE_ID_CLEAR);
    }
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
