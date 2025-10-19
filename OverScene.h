#pragma once
#include "Engine/GameObject.h"

class OverScene : public GameObject
{
public:
	OverScene(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};