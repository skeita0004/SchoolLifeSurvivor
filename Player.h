#pragma once
#include "Engine/GameObject.h"

class Stage;
class SceneManager;

class Player : public GameObject
{
public:
    Player(GameObject* _parent);
    ~Player();

    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;

    void SetFatigueLevel(int _fatigueLevel)
    {
        fatigueLevel_ = _fatigueLevel;
    }

    int GetFatigueLevel()
    {
        return fatigueLevel_;
    }

    void SetGraduationLimit(int _graduationLimit)
    {
        graduationLimit_ = _graduationLimit;
    }

    int GetGraduationLimit()
    {
        return graduationLimit_;
    }

    bool IsAssignedHomeWork()
    {
        return assignedHomeWork_;
    }

    void CompleteHomeWork()
    {
        assignedHomeWork_ = false;
        homeWorkProgress_ = 0;
    }

    void AssignHomeWork()
    {
        assignedHomeWork_ = true;
    }

    void AddHomeWorkProgress()
    {
        homeWorkProgress_ += 1;
    }

    int GetHomeWorkProgress()
    {
        return homeWorkProgress_;
    }

    void Bounce()
    {
        dy_ = 0.45f;   // 通常ジャンプと同じくらい
        isGrounded_ = false;
    }

    void OnDamaged()
    {
        // 的確なノックバック
        dy_ = 0.2f;
        fatigueLevel_ += 10;
    }
private:
    void ApplyTileCollision(Stage* stage, float& dx, float& dy);
    int hModel_;
    bool isGrounded_;
    float dy_;
    int fatigueLevel_;
    int graduationLimit_;
    bool assignedHomeWork_;
    int homeWorkProgress_;
    SceneManager* pSceneManager_;
};