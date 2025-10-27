#include "GuideScene.h"
#include "Input.h"
#include <typeinfo>

GuideScene::GuideScene(GameObject* _parent) :
    GameObject(_parent, "GuideScene"),
    pSceneManager_(nullptr)
{
}

void GuideScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
}

void GuideScene::Update()
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

void GuideScene::Draw()
{
}

void GuideScene::Release()
{
}
