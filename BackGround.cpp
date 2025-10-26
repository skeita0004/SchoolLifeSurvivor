#include "BackGround.h"

BackGround::BackGround(GameObject* _parent) :
    GameObject(_parent, "BackGround"),
    hImage_(-1)
{
}

BackGround::~BackGround()
{
}

void BackGround::Initialize()
{
    /* noimage.pngという、
    バックグラウンドが設定されていないことを示す画像を用意する。*/
    //hImage_ = Image::Load("noimage.png");
}

void BackGround::Update()
{
}

void BackGround::Draw()
{
    Image::Draw(hImage_);
}

void BackGround::Release()
{
}

void BackGround::SetBackGround(const std::string& _imagePath)
{
    hImage_ = Image::Load(_imagePath);
}
