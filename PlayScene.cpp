#include "PlayScene.h"
#include "Stage.h"
#include "BackGround.h"
#include "Input.h"
#include "Sprite.h"
#include "SceneManager.h"
#include "Player.h"

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
    pBackGround_->SetBackGround("images/play_bg.png");
    Instantiate<Stage>(this);
}

void PlayScene::Update()
{
    static Player* pPlayer = static_cast<Player*>(FindObject("Player"));
    if (pPlayer->GetFatigueLevel() >= 100)
    {
        pPlayer->KillMe();
        pSceneManager_->ChangeScene(SCENE_ID_OVER);
    }
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
