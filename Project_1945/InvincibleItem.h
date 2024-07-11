#pragma once

#include "Item.h"

class CInvincibleItem final
    : public CItem
{
public:
	CInvincibleItem();
	virtual ~CInvincibleItem() override;

	void Apply_Ability() override;
	virtual void Render(HDC hDC) override;
};

