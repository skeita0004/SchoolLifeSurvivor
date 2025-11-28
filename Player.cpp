#include "Player.h"
#include "Input.h"
#include "Camera.h"
#include "Stage.h"

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
    transform_.position_ = XMFLOAT3(0, 6, 0);
    hModel_ = Model::Load("models/player.fbx");
}

void Player::Update()
{
    static Stage* pStage = static_cast<Stage*>(FindObject("Stage"));
    static int          grassModelHandle = pStage->GetModelHandle(Stage::BlockType::B_GRASS);

    RayCastData rCData{};
    rCData.start = transform_.position_;
    rCData.dir = XMFLOAT3(0, -1, 0);
    Model::RayCast(grassModelHandle, &rCData);

    //transform_.position_.y -= rCData.dist;

    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= 0.5f;
    }
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += 0.5f;
    }

    XMVECTOR vPos;
    vPos = XMLoadFloat3(&transform_.position_);

    XMVECTOR vCamPos    = vPos + XMVectorSet(2, 12, -40, 0);
    XMVECTOR vCamTarget = vPos + XMVectorSet(2, 12, 0, 0);

    XMFLOAT3 camPos;
    XMFLOAT3 camTarget;

    XMStoreFloat3(&camPos, vCamPos);
    XMStoreFloat3(&camTarget, vCamTarget);
    Camera::SetPosition(camPos);
    Camera::SetTarget(camTarget);
}

void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Player::Release()
{
}
