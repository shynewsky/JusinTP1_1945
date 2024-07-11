#include "pch.h"
#include "PowerItem.h"

#include "Player.h"

CPowerItem::CPowerItem()
{
}

CPowerItem::~CPowerItem()
{
}

void CPowerItem::Apply_Ability()
{
	CPlayer* pPlayer = dynamic_cast<CPlayer*>(m_pPlayer);

	if (pPlayer != nullptr)
	{
		pPlayer->Level_UP();
	}
}

void CPowerItem::Render(HDC hDC)
{
	CItem::Render(hDC);

	TCHAR buffer[10] = L"P";

	RECT rcItem;
	rcItem.left = m_tObjInfo.fX - 10;
	rcItem.top = m_tObjInfo.fY - 10;
	rcItem.right = m_tObjInfo.fX + 10;
	rcItem.bottom = m_tObjInfo.fY + 10;

	DrawText(hDC, buffer, lstrlen(buffer), &rcItem, DT_CENTER);
}