#include "TestScene.h"

//コンストラクタ
TestScene::TestScene(GameObject* _parent):
    GameObject(_parent, "TestScene"),
    pSceneManager_(nullptr)
{
}

//初期化
void TestScene::Initialize()
{
}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
