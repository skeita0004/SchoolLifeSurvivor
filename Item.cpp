#include "Item.h"
#include <vector>
#include "Model.h"
#include "Player.h"
#include "SphereCollider.h"

namespace
{
    const std::string paths[]
    {
        "models/bed.fbx",
        "models/classwork.fbx",
        "models/homework.fbx",
        "models/pc.fbx"
    };
}

Item::Item(GameObject* _parent) :
    GameObject(_parent, "Item"),
    hModel_(-1),
    isObtained_(false)
{
}

void Item::Initialize()
{
    SphereCollider* pCollider = new SphereCollider(transform_.position_, 1.f);
    AddCollider(pCollider);
}

void Item::Update()
{
    static Player* pPlayer = static_cast<Player*>(FindObject("Player"));
    if (GetObjectName() == "Bed")
    {
        static int handle = Model::Load(paths[0]);
        hModel_ = handle;
    }
    else if (GetObjectName() == "Classwork")
    {
        static int handle = Model::Load(paths[1]);
        hModel_ = handle;
    }
    else if (GetObjectName() == "Homework")
    {
        static int handle = Model::Load(paths[2]);
        hModel_ = handle;
    }
    else if (GetObjectName() == "Pc")
    {
        static int handle = Model::Load(paths[3]);
        hModel_ = handle;
    }
    else
    {
        return;
    }

    if (isObtained_)
    {
        if (GetObjectName() == "Bed")
        {
            // 疲労回復
             int fl = pPlayer->GetFatigueLevel();
             fl -= 30;
             if (fl <= 0)
             {
                 fl = 0;
             }
             pPlayer->SetFatigueLevel(fl);
             KillMe();

        }
        else if (GetObjectName() == "Classwork")
        {
            // 日数減
            int gdl = pPlayer->GetGraduationLimit();
            gdl -= 50;
            pPlayer->SetGraduationLimit(gdl);
            KillMe();

        }
        else if (GetObjectName() == "Homework")
        {
            // 課題割当
            if (not(pPlayer->IsAssignedHomeWork()))
            {
                pPlayer->AssignHomeWork();
            }
            KillMe();
        }
        else if (GetObjectName() == "Pc")
        {
            // 課題消化
            if (pPlayer->IsAssignedHomeWork())
            {
                pPlayer->AddHomeWorkProgress();
                if (pPlayer->GetHomeWorkProgress() >= 5)
                {
                    pPlayer->CompleteHomeWork();
                    int gdl = pPlayer->GetGraduationLimit();
                    gdl -= 60;
                    pPlayer->SetGraduationLimit(gdl);
                }
                KillMe();
            }
        }
        else
        {
            return;
        }
        isObtained_ = false;
    }
}

void Item::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Item::Release()
{
}

void Item::OnCollision(GameObject* _pTarget)
{
    if (_pTarget->GetObjectName() == "Player")
    {
        isObtained_ = true;
    }
}
