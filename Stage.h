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

};