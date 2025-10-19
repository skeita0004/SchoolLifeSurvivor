#include "PlayScene.h"
#include <typeinfo>

PlayScene::PlayScene(GameObject* _parent):
    GameObject(_parent, typeid(this).name()),
    pSceneManager_(nullptr)
{
}

void PlayScene::Initialize()
{
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
