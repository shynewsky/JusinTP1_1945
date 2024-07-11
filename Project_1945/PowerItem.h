#pragma once

#include "Item.h"

class CPowerItem final
	: public CItem
{
public:
	CPowerItem();
	virtual ~CPowerItem() override;

public:
	void Apply_Ability() override;
	virtual void Render(HDC hDC) override;
};

