#include "Enemy.h"
#include <vector>
#include "Model.h"
#include "Player.h"
#include "BoxCollider.h"
#include <cmath>

namespace
{
    const std::string paths[]
    {
        "models/enemy/gameenemy.fbx",
        "models/enemy/Smartphoneenemy.fbx",
    };
}

Enemy::Enemy(GameObject* _parent) :
    GameObject(_parent, "Enemy"),
    hModel_(-1),
    animTime_(0.0f),
    basePos_(0, 0, 0)
{
}

void Enemy::Initialize()
{
    BoxCollider* pCollider = new BoxCollider(transform_.position_, XMFLOAT3(1, 1, 1));
    AddCollider(pCollider);
}

void Enemy::Update()
{
    static Player* pPlayer = static_cast<Player*>(FindObject("Player"));
    if (GetObjectName() == "Game")
    {
        static int handle = Model::Load(paths[0]);
        hModel_ = handle;
    }
    else if (GetObjectName() == "Phone")
    {
        static int handle = Model::Load(paths[1]);
        hModel_ = handle;
    }
    else
    {
        return;
    }

    animTime_ += 0.05f;  // アニメーション速度

    // Game：上下に往復（イージング付き sin 波）
    if (GetObjectName() == "Game")
    {
        basePos_.y = 5;
        const float AMPLITUDE = 2.f;  // 振幅
        float yOffset = std::sinf(animTime_) * AMPLITUDE;

        transform_.position_.y = basePos_.y + yOffset;
    }

    // Phone：X方向に一定速度で移動
    if (GetObjectName() == "Phone")
    {
        const float SPEED = 0.05f;
        transform_.position_.x += SPEED;

        // 画面外に行きすぎないようループ（任意）
        if (transform_.position_.x > basePos_.x + 6.0f)
        {
            transform_.position_.x = basePos_.x;
        }
    }
}

void Enemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* _pTarget)
{
    if (_pTarget->GetObjectName() != "Player")
        return;

    Player* pPlayer = static_cast<Player*>(_pTarget);

    // -------------------------------
    // ★ プレイヤーと敵の位置
    // -------------------------------
    XMFLOAT3 pPos = pPlayer->GetPosition();
    XMFLOAT3 ePos = transform_.position_;

    // プレイヤーの球半径
    const float PR = 0.5f;          // SphereCollider(1.0f) なら半径 0.5

    float playerCenterY = pPos.y;
    float playerBottomY = pPos.y - PR;

    // 敵の大きさ（モデルが 1x1x1 ならこれでOK：必要なら調整）
    const float EH = 1.0f;          // 敵の高さ

    float enemyTopY = ePos.y + EH * 0.5f;

    // 小さな誤差吸収
    const float EPS = 0.05f;

    // -----------------------------------------------------------
    // ★ 1. 踏みつけ判定（プレイヤーが上からぶつかった）
    // -----------------------------------------------------------
    if (playerBottomY > enemyTopY - EPS &&
        playerCenterY > enemyTopY + 0.2f)
    {
        // 踏みつけ成功！
        isHit_ = true;      // 敵側のヒット

        // ★ プレイヤーに踏みつけジャンプを与える
        pPlayer->Bounce();  // Player に関数追加（下で示します）

        // ★ 敵を消す
        KillMe();
        return;
    }

    // -----------------------------------------------------------
    // ★ 2. 横からぶつかった → プレイヤーがダメージ
    // -----------------------------------------------------------
    pPlayer->OnDamaged();   // Player に実装
}