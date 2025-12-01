#include "Slide.h"
#include "BackGround.h"
#include "SceneManager.h"
#include "Input.h"

Slide::Slide(GameObject* _parent)
{
}

void Slide::Initialize()
{
    pBackGround_ = Instantiate<BackGround>(this);
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));

    imagePaths_.reserve(3);
    for (int i = 0; i < 3; i++)
    {
        imagePaths_.push_back("images/guide_bg_" + std::to_string(i) + ".png");
    }
}

void Slide::Update()
{
    static int index = 0;

    pBackGround_->SetBackGround(imagePaths_[index % 3]);

    if (Input::IsKeyDown(DIK_SPACE) || Input::IsPadButtonDown(XINPUT_GAMEPAD_A))
    {
        index++;
    }

}

void Slide::Draw()
{
}

void Slide::Release()
{
}
