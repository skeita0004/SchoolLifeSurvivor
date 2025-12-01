#include "OverScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "BackGround.h"

OverScene::OverScene(GameObject* _parent) :
    GameObject(_parent, "OverScene"),
    pSceneManager_(nullptr)
{
}

void OverScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
    pBackGround_ = Instantiate<BackGround>(this);
    pBackGround_->SetBackGround("images/over_bg.png");
}

void OverScene::Update()
{
    if (Input::IsKeyDown(DIK_T) || Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
    {
        pSceneManager_->ChangeScene(SCENE_ID_TITLE);
    }
}

void OverScene::Draw()
{
}

void OverScene::Release()
{
}
