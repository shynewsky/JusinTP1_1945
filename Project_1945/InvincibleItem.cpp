#include "pch.h"
#include "InvincibleItem.h"

#include "Player.h"

CInvincibleItem::CInvincibleItem()
{
}

CInvincibleItem::~CInvincibleItem()
{
}

void CInvincibleItem::Apply_Ability()
{
	CPlayer* pTmpPlayer = dynamic_cast<CPlayer*>(m_pPlayer);

	if (pTmpPlayer != nullptr)
	{
		pTmpPlayer->Set_Invincible();
	}
}

void CInvincibleItem::Render(HDC hDC)
{
	CItem::Render(hDC);

	TCHAR buffer[10] = L"I";

	RECT rcItem;
	rcItem.left = m_tObjInfo.fX - 10;
	rcItem.top = m_tObjInfo.fY - 10;
	rcItem.right = m_tObjInfo.fX + 10;
	rcItem.bottom = m_tObjInfo.fY + 10;

	DrawText(hDC, buffer, lstrlen(buffer), &rcItem, DT_CENTER);
}
