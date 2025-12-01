#pragma once
#include "GameObject.h"
#include <vector>

class Text;

class Stage : public GameObject
{
public:
    Stage(GameObject* _parent);
    ~Stage();

    void Initialize()    override;
    void Update()  override;
    void Draw()    override;
    void Release() override;

    enum struct BlockType : int
    {
        B_AIR = 0,
        B_BRICK,

        E_GAME = 10,
        E_PHONE,

        I_BED = 20,
        I_CLASS,
        I_HOMEWORK,
        I_COMPUTER,

        PLAYER = 30,
        GOAL,
    };

    // タイル数（座標→タイル変換用）
    int GetWidth() const { return stageMap[0].size(); }
    int GetHeight() const { return stageMap.size(); }

    BlockType GetTile(int tx, int ty) const;
private:
    struct StageObject
    {
        BlockType blockType;
        int              hModel;
        Transform        transform;
    };

    std::vector<std::vector<StageObject>> stageMap;

    Text* pTextFatigueLevel_;
    Text* pTextGraduationLimit_;
};