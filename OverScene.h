#pragma once
#include "Engine/GameObject.h"

class SceneManager;
class BackGround;

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
    BackGround* pBackGround_;
};