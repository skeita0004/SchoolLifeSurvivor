#include "PlayScene.h"
#include "Stage.h"
#include "BackGround.h"
#include "Input.h"
#include "Sprite.h"

PlayScene::PlayScene(GameObject* _parent):
    GameObject(_parent, "PlayScene"),
    pSceneManager_(nullptr),
    pBackGround_(nullptr)
{
}

void PlayScene::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
    pBackGround_ = Instantiate<BackGround>(this);
    // ここマジックナンバーだよ
    pBackGround_->SetBackGround("images/playSceneBG.png");
    Instantiate<Stage>(this);


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
