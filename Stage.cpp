#include "Stage.h"
#include <vector>
#include "CsvReader.h"
#include "Player.h"

namespace
{
    // 複数ステージを用意（やらないけど）するならメンバ変数にすること。
    std::vector<std::vector<int>> stageMap(0, std::vector<int>(0));
}

Stage::Stage(GameObject* _parent):
    GameObject(_parent, "Stage")
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
    Instantiate<Player>(GetParent());
    CsvReader stageData;
    //stageData.Load("map/map01.csv");

    for (int y = 0; y < stageData.GetHeight(); y++)
    {
        for (int x = 0; x < stageData.GetWidth(); x++)
        {
            BlockType block = static_cast<BlockType>(stageData.GetIntValue(x, y));
            
            switch (block) 
            {
            case Stage::BlockType::B_GRASS:
                break;
            case Stage::BlockType::B_BRICK:
                break;
            case Stage::BlockType::B_CLOUD_L:
                break;
            case Stage::BlockType::B_CLOUD_MID:
                break;
            case Stage::BlockType::B_CLOUD_R:
                break;
            case Stage::BlockType::E_GAME:
                break;
            case Stage::BlockType::E_PHONE:
                break;
            case Stage::BlockType::I_BED:
                break;
            case Stage::BlockType::I_CLASS:
                break;
            case Stage::BlockType::I_HOMEWORK:
                break;
            case Stage::BlockType::I_COMPUTER:
                break;
            default:
                break;
            }
        }
    }
}

void Stage::Update()
{
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
