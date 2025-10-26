#pragma once
#include "GameObject.h"
#include "Image.h"

class BackGround : public GameObject
{
public:
    BackGround(GameObject* _parent);
    ~BackGround();

    void Initialize() override;
    void Update()     override;
    void Draw()       override;
    void Release()    override;

    void SetBackGround(const std::string& _imagePath);
private:
    int hImage_;

};