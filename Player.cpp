#include "Player.h"
#include "Input.h"

Player::Player(GameObject* _parent) :
    GameObject(_parent, "Player"),
    hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    hModel_ = Model::Load("player.fbx");
}

void Player::Update()
{
    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= 2.f;
    }
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += 2.f;
    }
}

void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Player::Release()
{
}
