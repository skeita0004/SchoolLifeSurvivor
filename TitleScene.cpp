#include "TitleScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "BackGround.h"

TitleScene::TitleScene(GameObject* _parent) :
    GameObject(_parent, "TitleScene"),
    pSceneManager_(nullptr),
    pBackGround_(nullptr)
{
}

void TitleScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
    pBackGround_ = Instantiate<BackGround>(this);
    pBackGround_->SetBackGround("images/title_bg.png");
}

void TitleScene::Update()
{
    if (Input::IsKeyDown(DIK_P) || Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
    {
        pSceneManager_->ChangeScene(SCENE_ID_PLAY);
    }
    if (Input::IsKeyDown(DIK_G) || Input::IsPadButtonDown(XINPUT_GAMEPAD_X))
    {
        pSceneManager_->ChangeScene(SCENE_ID_GUIDE);
    }
    if (Input::IsKeyDown(DIK_ESCAPE) || Input::IsPadButtonDown(XINPUT_GAMEPAD_BACK))
    {
        PostQuitMessage(0);
    }
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
