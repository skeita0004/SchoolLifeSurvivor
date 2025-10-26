#pragma once
#include "GameObject.h"

class Stage : public GameObject
{
public:
    Stage(GameObject* _parent);
    ~Stage();

    void Initialize()    override;
    void Update()  override;
    void Draw()    override;
    void Release() override;

private:
    enum struct BlockType : int
    {
        B_GRASS = 0,
        B_BRICK,
        B_CLOUD_L,
        B_CLOUD_MID,
        B_CLOUD_R,

        E_GAME = 10,
        E_PHONE,

        I_BED = 20,
        I_CLASS,
        I_HOMEWORK,
        I_COMPUTER
    };
};