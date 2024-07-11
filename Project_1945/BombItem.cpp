#include "pch.h"
#include "BombItem.h"

#include "Player.h"

CBombItem::CBombItem()
{
}

CBombItem::~CBombItem()
{
}

void CBombItem::Apply_Ability()
{
	CPlayer* pTmpPlayer = dynamic_cast<CPlayer*>(m_pPlayer);

	if (pTmpPlayer != nullptr)
	{
		pTmpPlayer->Add_Bomb();
	}
}

void CBombItem::Render(HDC hDC)
{
	CItem::Render(hDC);

	TCHAR buffer[10] = L"B";

	RECT rcItem;
	rcItem.left = m_tObjInfo.fX - 10;
	rcItem.top = m_tObjInfo.fY - 10;
	rcItem.right = m_tObjInfo.fX + 10;
	rcItem.bottom = m_tObjInfo.fY + 10;

	DrawText(hDC, buffer, lstrlen(buffer), &rcItem, DT_CENTER);
}

