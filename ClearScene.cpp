#include "ClearScene.h"
#include <typeinfo>

ClearScene::ClearScene(GameObject* _parent):
    GameObject(_parent, typeid(this).name()),
    pSceneManager_(nullptr)
{
}

void ClearScene::Initialize()
{
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
}

void ClearScene::Release()
{
}
