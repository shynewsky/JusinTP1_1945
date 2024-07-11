#pragma once
#include "Item.h"

class CBombItem final
    : public CItem
{
public:
	CBombItem();
	virtual ~CBombItem() override;

	void Apply_Ability() override;

	virtual void	Render(HDC hDC) override;
};

