#include "ClearScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "BackGround.h"

ClearScene::ClearScene(GameObject* _parent):
    GameObject(_parent, "ClearScene"),
    pSceneManager_(nullptr)
{
}

void ClearScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
    pBackGround_ = Instantiate<BackGround>(this);
    pBackGround_->SetBackGround("images/clear_bg.png");
}

void ClearScene::Update()
{
    if (Input::IsKeyDown(DIK_T) || Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
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
