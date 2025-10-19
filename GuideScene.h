#pragma once
#include "Engine/GameObject.h"

class GuideScene : public GameObject
{
public:
	GuideScene(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};