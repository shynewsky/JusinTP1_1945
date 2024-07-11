#pragma once

#include "Item.h"

class CLifeItem final
    : public CItem
{
public:
	CLifeItem();
	virtual ~CLifeItem() override;

	void Apply_Ability() override;
	virtual void Render(HDC hDC) override;
};

