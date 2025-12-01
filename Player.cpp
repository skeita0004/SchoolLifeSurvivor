//#include "Player.h"
//#include "Input.h"
//#include "Camera.h"
//#include "Stage.h"
//#include "Model.h"
//
//Player::Player(GameObject* _parent) :
//    GameObject(_parent, "Player"),
//    hModel_(-1)
//{
//}
//
//Player::~Player()
//{
//}
//
//void Player::Initialize()
//{
//    transform_.position_ = XMFLOAT3(0, 4, 0);
//    hModel_ = Model::Load("models/player.fbx");
//}
//
//void Player::Update()
//{
//    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
//
//    //// レイキャスト準備
//    //static Stage* pStage = static_cast<Stage*>(FindObject("Stage"));
//    //static int    modelHandle = pStage->GetModelHandle(Stage::BlockType::B_BRICK);
//    //const XMVECTOR vRayCastOffset{ XMVectorSet(0, 10, 0, 0) };
//    //XMFLOAT3 rayCastStart{};
//    //RayCastData rCData{};
//    //XMStoreFloat3(&rayCastStart, vPos + vRayCastOffset);
//    //rCData.start = rayCastStart;
//    //rCData.dir = XMFLOAT3(0, -1, 0);
//    //Model::RayCast(modelHandle, &rCData);
//
//    //if (rCData.hit)
//    //{
//    //    transform_.position_.y -= rCData.dist;
//    //}
//
//    if (Input::IsKey(DIK_A))
//    {
//        transform_.position_.x -= 0.5f;
//    }
//    if (Input::IsKey(DIK_D))
//    {
//        transform_.position_.x += 0.5f;
//    }
//
//    //XMVECTOR vPos;
//    vPos = XMLoadFloat3(&transform_.position_);
//
//    XMVECTOR vCamPos    = vPos + XMVectorSet(2, 12, -40, 0);
//    XMVECTOR vCamTarget = vPos + XMVectorSet(2, 12, 0, 0);
//
//    XMFLOAT3 camPos;
//    XMFLOAT3 camTarget;
//
//    XMStoreFloat3(&camPos, vCamPos);
//    XMStoreFloat3(&camTarget, vCamTarget);
//    Camera::SetPosition(camPos);
//    Camera::SetTarget(camTarget);
//
//    XMStoreFloat3(&transform_.position_, vPos);
//}
//
//void Player::Draw()
//{
//    Model::SetTransform(hModel_, transform_);
//    Model::Draw(hModel_);
//}
//
//void Player::Release()
//{
//}

//#include "Player.h"
//#include "Input.h"
//#include "Camera.h"
//#include "Stage.h"
//#include "Model.h"
//
//Player::Player(GameObject* _parent) :
//    GameObject(_parent, "Player"),
//    hModel_(-1)
//{
//}
//
//Player::~Player()
//{
//}
//
//void Player::Initialize()
//{
//    transform_.position_ = XMFLOAT3(0, 10, 0);
//    hModel_ = Model::Load("models/player.fbx");
//}
//
//void Player::Update()
//{
//    static Stage* stage = static_cast<Stage*>(FindObject("Stage"));
//
//    float dx = 0;
//    float dy = -0.3f; // 重力
//
//    if (Input::IsKey(DIK_A)) dx -= 0.2f;
//    if (Input::IsKey(DIK_D)) dx += 0.2f;
//
//    ApplyTileCollision(stage, dx, dy);
//
//    transform_.position_.x += dx;
//    transform_.position_.y += dy;
//
//    // ---- カメラ設定 ---- //
//    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
//    XMVECTOR vCamPos = vPos + XMVectorSet(2, 12, -40, 0);
//    XMVECTOR vCamTarget = vPos + XMVectorSet(2, 12, 0, 0);
//
//    XMFLOAT3 camPos, camTarget;
//    XMStoreFloat3(&camPos, vCamPos);
//    XMStoreFloat3(&camTarget, vCamTarget);
//
//    Camera::SetPosition(camPos);
//    Camera::SetTarget(camTarget);
//}
//
//void Player::ApplyTileCollision(Stage* stage, float& dx, float& dy)
//{
//    // プレイヤーの足元・左右のタイルを判定
//    XMFLOAT3 pos = transform_.position_;
//
//    // プレイヤーを1x2 タイル分として扱う想定（調整可能）
//    float halfW = 0.8f;
//    float halfH = 1.8f;
//
//    // 移動後の仮位置
//    float newX = pos.x + dx;
//    float newY = pos.y + dy;
//
//    // タイル座標へ変換（タイル1個=2.0f のため  /2）
//    int tx = (int)(newX / 2.0f);
//    int ty = (int)((stage->GetHeight() * 2 - newY - 1) / 2.0f);
//
//    // ---- 足元（落下判定） ----
//    if (dy < 0)
//    {
//        int ty_bottom = (int)((stage->GetHeight() * 2 - (pos.y - halfH)) / 2.0f);
//
//        if (stage->GetTile(tx, ty_bottom) == Stage::BlockType::B_BRICK)
//        {
//            dy = 0; // 地面に乗る
//        }
//    }
//
//    // ---- 左 ----
//    if (dx < 0)
//    {
//        int tx_left = (int)((newX - halfW) / 2.0f);
//
//        if (stage->GetTile(tx_left, ty) == Stage::BlockType::B_BRICK)
//        {
//            dx = 0;
//        }
//    }
//
//    // ---- 右 ----
//    if (dx > 0)
//    {
//        int tx_right = (int)((newX + halfW) / 2.0f);
//
//        if (stage->GetTile(tx_right, ty) == Stage::BlockType::B_BRICK)
//        {
//            dx = 0;
//        }
//    }
//}
//
//void Player::Draw()
//{
//    Model::SetTransform(hModel_, transform_);
//    Model::Draw(hModel_);
//}
//
//void Player::Release()
//{
//}

#include "Player.h"
#include "Input.h"
#include "Camera.h"
#include "Stage.h"
#include "Model.h"
#include "SceneManager.h"
#include "SphereCollider.h"

Player::Player(GameObject* _parent) :
    GameObject(_parent, "Player"),
    hModel_(-1),
    isGrounded_(false),
    dy_(0.0f),
    graduationLimit_(600),
    fatigueLevel_(0)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
    SphereCollider* pCollider = new SphereCollider(transform_.position_, 1.f);
    transform_.position_ = XMFLOAT3(1, 10, 0);
    hModel_ = Model::Load("models/player.fbx");
    AddCollider(pCollider);

    isGrounded_ = false;
    dy_ = 0.0f;
}

void Player::Update()
{
    static Stage* stage = static_cast<Stage*>(FindObject("Stage"));

    float dx = 0.0f;

    // dyはメンバ変数である必要がないかも…

    // ---- 横移動 ---- //
    if (Input::IsKey(DIK_A) || Input::IsPadButton(XINPUT_GAMEPAD_DPAD_LEFT)) dx -= 0.3f;
    if (Input::IsKey(DIK_D) || Input::IsPadButton(XINPUT_GAMEPAD_DPAD_RIGHT)) dx += 0.3f;

    // ---- ジャンプ ---- //
    if ((Input::IsKeyDown(DIK_SPACE) || Input::IsPadButton(XINPUT_GAMEPAD_A)) && isGrounded_)
    {
        dy_ = 0.45f;
        isGrounded_ = false;
    }

    // ---- 重力 ---- //
    dy_ -= 0.02f;
    if (dy_ < -0.5f) dy_ = -0.5f;

    // ---- 衝突処理 ---- //
    ApplyTileCollision(stage, dx, dy_);

    // ---- 位置反映 ---- //
    transform_.position_.x += dx;
    transform_.position_.y += dy_;

    // ---- カメラ ---- //
    const float CAM_Y = 10.0f; // 完全固定

    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);
    XMFLOAT3 playerPos;
    XMStoreFloat3(&playerPos, vPos);

    XMVECTOR vCamPos = XMVectorSet(playerPos.x + 2.0f, CAM_Y, playerPos.z - 25.0f, 0.0f);
    XMVECTOR vCamTarget = XMVectorSet(playerPos.x + 2.0f, CAM_Y, playerPos.z, 0.0f);

    XMFLOAT3 camPos, camTarget;
    XMStoreFloat3(&camPos, vCamPos);
    XMStoreFloat3(&camTarget, vCamTarget);

    Camera::SetPosition(camPos);
    Camera::SetTarget(camTarget);

    if (transform_.position_.y <= -10)
    {
        pSceneManager_->ChangeScene(SCENE_ID::SCENE_ID_OVER);
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

//
// ★ タイル衝突処理（完全修正版）
//
void Player::ApplyTileCollision(Stage* stage, float& dx, float& dy)
{
    const float BLOCK = 1.0f;     // ブロックのサイズ（ステージ座標）
    const float P_W = 1.0f;       // プレイヤーの幅（ステージ座標）
    const float P_H = 2.0f;       // プレイヤーの高さ（ステージ座標）
    const float MODEL_OFFSET_RIGHT = 0.25f;
    const float MODEL_OFFSET_LEFT = -0.15f;

    XMFLOAT3 pos = transform_.position_;


    float foot = pos.y;          // プレイヤー足元
    float head = pos.y + P_H;    // プレイヤー頭
    float left = (pos.x - P_W * 0.5f) + MODEL_OFFSET_LEFT;
    float right = (pos.x + P_W * 0.5f) + MODEL_OFFSET_RIGHT;

    float nextFoot = foot + dy;
    float nextHead = head + dy;
    float nextLeft = left + dx;
    float nextRight = right + dx;

    isGrounded_ = false;

    int stageH = stage->GetHeight();

    // -----------------------------------------
    // ★ Y方向の衝突
    // -----------------------------------------

    // 画面Y → CSV_Y
    auto ToCSVY = [&](float yReal)
        {
            return (stageH - 1) - (int)floor(yReal / BLOCK);
        };

    int csvX = (int)floor(pos.x / BLOCK);
    int csvY = ToCSVY(nextFoot);

    // ---- 地面衝突 ---- //
    if (dy < 0)
    {
        if (stage->GetTile(csvX, csvY) == Stage::BlockType::B_BRICK)
        {
            // ブロック上面（画面座標）
            float blockTop = (stageH - 1 - csvY) * BLOCK + BLOCK;

            if (nextFoot < blockTop)
            {
                transform_.position_.y = blockTop;
                dy = 0;
                isGrounded_ = true;

                pos = transform_.position_;
                foot = pos.y;
                nextFoot = foot;
            }
        }
    }

    // ---- 天井衝突 ---- //
    if (dy > 0)
    {
        int hitY = ToCSVY(nextHead);

        if (stage->GetTile(csvX, hitY) == Stage::BlockType::B_BRICK)
        {
            float blockBottom = (stageH - 1 - hitY) * BLOCK;

            if (nextHead > blockBottom)
            {
                transform_.position_.y = blockBottom - P_H;
                dy = 0;

                pos = transform_.position_;
                head = pos.y + P_H;
                nextHead = head;
            }
        }
    }

    // -----------------------------------------
    // ★ X方向の衝突
    // -----------------------------------------

    pos = transform_.position_;

    foot = pos.y;
    head = pos.y + P_H;

    //left = pos.x - P_W * 0.5f;
    //right = pos.x + P_W * 0.5f;

    nextLeft = left + dx;
    nextRight = right + dx;

    int tileY1 = ToCSVY(foot);
    int tileY2 = ToCSVY(head - 0.01f);
    if (tileY1 > tileY2) std::swap(tileY1, tileY2);

    // ---- 左 ----
    if (dx < 0)
    {
        int tileX = (int)floor((nextLeft + 0.0001f) / BLOCK);

        for (int ty = tileY1; ty <= tileY2; ty++)
        {
            if (stage->GetTile(tileX, ty) == Stage::BlockType::B_BRICK)
            {
                dx = 0;
                break;
            }
        }
    }

    // ---- 右 ----
    if (dx > 0)
    {
        int tileX = (int)floor((nextRight - 0.0001f) / BLOCK);

        for (int ty = tileY1; ty <= tileY2; ty++)
        {
            if (stage->GetTile(tileX, ty) == Stage::BlockType::B_BRICK)
            {
                dx = 0;
                break;
            }
        }
    }

}
