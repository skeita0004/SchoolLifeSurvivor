#include "Stage.h"
#include <vector>
#include "CsvReader.h"
#include "Player.h"
#include "Model.h"

namespace
{


    struct StageObject
    {
        Stage::BlockType blockType;
        int              hModel;
        Transform        transform;
    };

    const std::vector<std::string> objectPaths
    {
        "grass.fbx"
    };

    // 複数ステージを用意（やらないけど）するならメンバ変数にすること。
    std::vector<std::vector<StageObject>> 
        stageMap(0, std::vector<StageObject>(0));

    const std::string MAP_FILE_NAME{"stageMap.csv"};
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
    stageData.Load(MAP_FILE_NAME);

    stageMap.resize(stageData.GetHeight());

    for (int i = 0; i < stageMap.size(); i++)
    {
        stageMap[i].resize(stageData.GetWidth());
    }

    for (int y = 0; y < stageData.GetHeight(); y++)
    {
        for (int x = 0; x < stageData.GetWidth(); x++)
        {
            BlockType block = static_cast<BlockType>(stageData.GetIntValue(x, y));
            
            switch (block) 
            {
            using enum BlockType;
            case BlockType::B_GRASS:
                stageMap[y][x].blockType = block;
                stageMap[y][x].hModel = Model::Load(objectPaths[(int)block]);
                stageMap[y][x].transform.position_ = XMFLOAT3(x, y, 0);
                break;
            case BlockType::B_BRICK:
                break;
            case BlockType::B_CLOUD_L:
                break;
            case BlockType::B_CLOUD_MID:
                break;
            case BlockType::B_CLOUD_R:
                break;
            case BlockType::E_GAME:
                break;
            case BlockType::E_PHONE:
                break;
            case BlockType::I_BED:
                break;
            case BlockType::I_CLASS:
                break;
            case BlockType::I_HOMEWORK:
                break;
            case BlockType::I_COMPUTER:
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
    for (int y = 0; y < stageMap.size(); y++)
    {
        for (int x = 0; x < stageMap[y].size(); x++)
        {
            if (stageMap[y][x].hModel == 0)
            {
                continue;
            }
            int hModel = stageMap[y][x].hModel;
            Transform transform = stageMap[y][x].transform;
            transform.position_ = { (float)x * 2, (float)y * 2 - 14.f, 0 };
            Model::SetTransform(hModel, transform);
            Model::Draw(hModel);
        }
    }
}

void Stage::Release()
{
}

int Stage::GetModelHandle(BlockType _type)
{
    for (int y = 0; y < stageMap.size(); y++)
    {
        for (int x = 0; x < stageMap[y].size(); x++)
        {
            StageObject object = stageMap[y][x];
            if (object.blockType == _type)
            {
                return object.hModel;
            }
        }
    }
}
