#pragma once
#include "Engine/GameObject.h"
#include "SceneManager.h"

class SceneManager;

class OverScene : public GameObject
{
public:
	OverScene(GameObject* _parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

private:
	SceneManager* pSceneManager_;
};