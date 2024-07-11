#pragma once
#include "pch.h"
#include "Windows.h"
#include "Enemy.h"

class CBoss : public CEnemy
{
public:
	CBoss();
	virtual ~CBoss();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override ;
	virtual void Release() override;
};