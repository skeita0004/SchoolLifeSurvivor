#include "GuideScene.h"
#include "Input.h"
#include "Slide.h"

GuideScene::GuideScene(GameObject* _parent) :
    GameObject(_parent, "GuideScene"),
    pSceneManager_(nullptr)
{
}

void GuideScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
    Instantiate<Slide>(this);
}

void GuideScene::Update()
{
    if (Input::IsKeyDown(DIK_T) || Input::IsPadButtonDown(XINPUT_GAMEPAD_B))
    {
        pSceneManager_->ChangeScene(SCENE_ID_TITLE);
    }

    if (Input::IsKeyDown(DIK_P) || Input::IsPadButtonDown(XINPUT_GAMEPAD_START))
    {
        pSceneManager_->ChangeScene(SCENE_ID_PLAY);
    }
}

void GuideScene::Draw()
{
}

void GuideScene::Release()
{
}
