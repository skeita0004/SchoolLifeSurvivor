#include "TitleScene.h"
#include <typeinfo>

TitleScene::TitleScene(GameObject* _parent) :
    GameObject(_parent, typeid(this).name()),
    pSceneManager_(nullptr)
{
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
