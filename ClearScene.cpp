#include "ClearScene.h"
#include "Input.h"

ClearScene::ClearScene(GameObject* _parent):
    GameObject(_parent, "ClearScene"),
    pSceneManager_(nullptr)
{
}

void ClearScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
}

void ClearScene::Update()
{
    if (Input::IsKeyDown(DIK_T))
    {
        pSceneManager_->ChangeScene(SCENE_ID_TITLE);
    }
}

void ClearScene::Draw()
{
}

void ClearScene::Release()
{
}
