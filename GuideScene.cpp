#include "GuideScene.h"
#include <typeinfo>

GuideScene::GuideScene(GameObject* _parent) :
    GameObject(_parent, typeid(this).name()),
    pSceneManager_(nullptr)
{
}

void GuideScene::Initialize()
{
}

void GuideScene::Update()
{
}

void GuideScene::Draw()
{
}

void GuideScene::Release()
{
}
