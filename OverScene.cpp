#include "OverScene.h"
#include <typeinfo>

OverScene::OverScene(GameObject* _parent) :
    GameObject(_parent, typeid(this).name()),
    pSceneManager_(nullptr)
{
}

void OverScene::Initialize()
{
}

void OverScene::Update()
{
}

void OverScene::Draw()
{
}

void OverScene::Release()
{
}
