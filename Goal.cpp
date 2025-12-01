#include "Goal.h"
#include "SceneManager.h"
#include "SphereCollider.h"
#include "Model.h"
#include "Player.h"

Goal::Goal(GameObject* _parent) :
    GameObject(_parent, "Goal")
{
}

void Goal::Initialize()
{
    pSceneManager_ = static_cast<SceneManager*>(FindObject("SceneManager"));
    SphereCollider* collider = new SphereCollider(transform_.position_, 1.f);
    AddCollider(collider);
    hModel_ = Model::Load("models/goal.fbx");
}

void Goal::Update()
{
    static Player* pPlayer = static_cast<Player*>(FindObject("Player"));
    if (isGoaled_)
    {
        if (pPlayer->GetGraduationLimit() <= 0)
        {
            pSceneManager_->ChangeScene(SCENE_ID_CLEAR);
        }
        else
        {
            pSceneManager_->ChangeScene(SCENE_ID_OVER);
        }
    }
}

void Goal::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Goal::Release()
{
}

void Goal::OnCollision(GameObject* _pTarget)
{
    if (_pTarget->GetObjectName() == "Player")
    {
        isGoaled_ = true;
    }
}
