//#include "Stage.h"
//#include <vector>
//#include "CsvReader.h"
//#include "Model.h"
//#include "Player.h"
//
//namespace
//{
//
//
//    struct StageObject
//    {
//        Stage::BlockType blockType;
//        int              hModel;
//        Transform        transform;
//    };
//
//    const std::vector<std::string> objectPaths
//    {
//        "air",
//        "models/brick.fbx"
//    };
//
//    // 複数ステージを用意（やらないけど）するならメンバ変数にすること。
//    std::vector<std::vector<StageObject>> 
//        stageMap(0, std::vector<StageObject>(0));
//
//    const std::string MAP_FILE_NAME{"datas/stageMap.csv"};
//}
//
//Stage::Stage(GameObject* _parent):
//    GameObject(_parent, "Stage")
//{
//}
//
//Stage::~Stage()
//{
//}
//
//void Stage::Initialize()
//{
//    Instantiate<Player>(GetParent());
//    CsvReader stageData;
//    stageData.Load(MAP_FILE_NAME);
//
//    stageMap.resize(stageData.GetHeight());
//
//    for (int i = 0; i < stageMap.size(); i++)
//    {
//        stageMap[i].resize(stageData.GetWidth());
//    }
//
//    for (int y = 0; y < stageData.GetHeight(); y++)
//    {
//        for (int x = 0; x < stageData.GetWidth(); x++)
//        {
//            BlockType block = static_cast<BlockType>(stageData.GetIntValue(x, y));
//            
//            // これswitchじゃなくてよくないか？
//            switch (block) 
//            {
//            using enum BlockType;
//            case BlockType::B_BRICK:
//                stageMap[y][x].blockType = block;
//                stageMap[y][x].hModel = Model::Load(objectPaths[(int)block]);
//                stageMap[y][x].transform.position_ = XMFLOAT3(x * 2, y * 2, 0);
//                break;
//
//            case BlockType::GOAL:
//
//
//            case BlockType::B_AIR:
//                stageMap[y][x].blockType = block;
//                stageMap[y][x].hModel = -1;
//                stageMap[y][x].transform.position_ = XMFLOAT3(x * 2, y * 2, 0);
//                break;
//
//            case BlockType::E_GAME:
//                break;
//
//            case BlockType::E_PHONE:
//                break;
//
//            case BlockType::I_BED:
//                break;
//
//            case BlockType::I_CLASS:
//                break;
//
//            case BlockType::I_HOMEWORK:
//                break;
//
//            case BlockType::I_COMPUTER:
//                break;
//
//            default:
//                break;
//            }
//        }
//    }
//}
//
//void Stage::Update()
//{
//}
//
//void Stage::Draw()
//{
//    for (int y = 0; y < stageMap.size(); y++)
//    {
//        for (int x = 0; x < stageMap[y].size(); x++)
//        {
//            // airならばスキップ
//            if (stageMap[y][x].blockType == BlockType::B_AIR)
//            {
//                continue;
//            }
//
//            int hModel = stageMap[y][x].hModel;
//            Transform transform = stageMap[y][x].transform;
//            transform.position_.y = (((stageMap.size() - 1) - y) * 2);
//
//
//            Model::SetTransform(hModel, transform);
//            Model::Draw(hModel);
//        }
//    }
//}
//
//void Stage::Release()
//{
//}
//
//int Stage::GetModelHandle(BlockType _type)
//{
//    for (int y = 0; y < stageMap.size(); y++)
//    {
//        for (int x = 0; x < stageMap[y].size(); x++)
//        {
//            StageObject object = stageMap[y][x];
//            if (object.blockType == _type)
//            {
//                return object.hModel;
//            }
//        }
//    }
//}
#include "Stage.h"
#include <vector>
#include "CsvReader.h"
#include "Model.h"
#include "Player.h"
#include "Goal.h"
#include "Item.h"
#include "Enemy.h"
#include <DirectXMath.h>
#include "Text.h"
#include <string>

namespace
{
    const std::vector<std::string> objectPaths{
        "air",
        "models/brick.fbx"
    };

    const std::string MAP_FILE_NAME{ "datas/stageMap.csv" };
}

Stage::Stage(GameObject* _parent) :
    GameObject(_parent, "Stage")
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
    pTextFatigueLevel_ = new Text();
    pTextGraduationLimit_ = new Text();

    pTextFatigueLevel_->Initialize();
    pTextGraduationLimit_->Initialize();
    Instantiate<Player>(GetParent());

    CsvReader stageData;
    stageData.Load(MAP_FILE_NAME);

    stageMap.resize(stageData.GetHeight());
    for (int y = 0; y < stageMap.size(); y++)
    {
        stageMap[y].resize(stageData.GetWidth());
    }

    for (int y = 0; y < stageData.GetHeight(); y++)
    {
        for (int x = 0; x < stageData.GetWidth(); x++)
        {
            BlockType block = static_cast<BlockType>(stageData.GetIntValue(x, y));

            StageObject& obj = stageMap[y][x];
            obj.blockType = block;

            switch (block)
            {
            case Stage::BlockType::B_AIR:
                obj.hModel = -1;
                break;
            case Stage::BlockType::B_BRICK:
                obj.hModel = Model::Load(objectPaths[(int)block]);
                break;
            case Stage::BlockType::E_GAME:
            {
                obj.hModel = -1;
                Enemy* pEnemy = Instantiate<Enemy>(this);
                pEnemy->SetPosition(XMFLOAT3(x * 1.0f, ((stageMap.size() - 1) - y) * 1.0f, 0));
                pEnemy->SetName("Game");
                pEnemy->SetRotateY(180);
                break;
            }
            case Stage::BlockType::E_PHONE:
            {
                obj.hModel = -1;
                Enemy* pEnemy = Instantiate<Enemy>(this);
                pEnemy->SetPosition(XMFLOAT3(x * 1.0f, ((stageMap.size() - 1) - y) * 1.0f, 0));
                pEnemy->SetName("Phone");
                pEnemy->SetRotateY(180);
                break;
            }
            case Stage::BlockType::I_BED:
            {
                obj.hModel = -1;
                Item* pItem = Instantiate<Item>(this);
                pItem->SetPosition(XMFLOAT3(x * 1.0f, ((stageMap.size() - 1) - y) * 1.0f, 0));
                pItem->SetName("Bed");
                break;
            }
            case Stage::BlockType::I_CLASS:
            {
                obj.hModel = -1;
                Item* pItem = Instantiate<Item>(this);
                pItem->SetPosition(XMFLOAT3(x * 1.0f, ((stageMap.size() - 1) - y) * 1.0f, 0));

                pItem->SetName("Classwork");
                break;
            }
            case Stage::BlockType::I_HOMEWORK:
            {
                obj.hModel = -1;
                Item* pItem = Instantiate<Item>(this);
                pItem->SetPosition(XMFLOAT3(x * 1.0f, ((stageMap.size() - 1) - y) * 1.0f, 0));

                pItem->SetName("Homework");
                break;
            }
            case Stage::BlockType::I_COMPUTER:
            {
                obj.hModel = -1;
                Item* pItem = Instantiate<Item>(this);
                pItem->SetPosition(XMFLOAT3(x * 1.0f, ((stageMap.size() - 1) - y) * 1.0f, 0));

                pItem->SetName("Pc");
                break;
            }
            case Stage::BlockType::PLAYER:
                obj.hModel = -1;
                break;
            case Stage::BlockType::GOAL:
            {

                obj.hModel = -1;
                Goal* pGoal = Instantiate<Goal>(this);
                pGoal->SetPosition(x, ((stageMap.size() - 1) - y), 0);
                break;
            }
            default:
                break;
            }

            // タイル = 1x1x1 なのでそのまま
            obj.transform.position_ =
                XMFLOAT3(x * 1.0f, ((stageMap.size() - 1) - y) * 1.0f, 0);
        }
    }
}

void Stage::Update()
{

}

void Stage::Draw()
{
    static Player* pPlayer = static_cast<Player*>(FindObject("Player"));

    for (int y = 0; y < stageMap.size(); y++)
    {
        for (int x = 0; x < stageMap[y].size(); x++)
        {
            if (stageMap[y][x].blockType == BlockType::B_AIR) continue;

            auto& obj = stageMap[y][x];
            Model::SetTransform(obj.hModel, obj.transform);
            Model::Draw(obj.hModel);
        }
    }
    std::string fatigueLevel{ "FatigueLevel : " + std::to_string(pPlayer->GetFatigueLevel()) };
    std::string graduationLimit{ "GraduationLimit : " + std::to_string(pPlayer->GetGraduationLimit()) + "days"};
    pTextFatigueLevel_->Draw(900, 20, fatigueLevel.c_str());
    pTextGraduationLimit_->Draw(800, 60, graduationLimit.c_str());
}

void Stage::Release()
{
}

Stage::BlockType Stage::GetTile(int tx, int ty) const
{
    if (ty < 0 || ty >= stageMap.size()) return BlockType::B_AIR;
    if (tx < 0 || tx >= stageMap[0].size()) return BlockType::B_AIR;

    return stageMap[ty][tx].blockType;
}
