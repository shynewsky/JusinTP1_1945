#include "pch.h"
#include "Boss.h"

CBoss::CBoss()
{
}

CBoss::~CBoss()
{
	Release();
}

void CBoss::Initialize()
{
	m_eObjId = OBJ_BOSS;
	m_tObjInfo.fCX = 150.f; // 비행기 크기
	m_tObjInfo.fCY = 150.f; // 비행기 크기
	m_fSpeed = 1.f; // 비행기 속도
	m_iHp = 200;
	m_iMaxHp = m_iHp;
}
int CBoss::Update()
{
	{
		CEnemy::Update();
		if (m_bDead) { return OBJ_DEAD; } // 1 

		if (m_tObjInfo.fY < 100)
		{
			m_tObjInfo.fY += m_fSpeed;
		}
		else
		{
			m_tObjInfo.fX -= m_fSpeed;
			if (m_tObjInfo.fX < 100 || m_tObjInfo.fX > 400)
			{
				m_fSpeed *= (-1.f);
			}
		}

		Create_Bullet_Boss();

		__super::Update_Pos();
		return OBJ_NOEVENT; // 0
	}
}

void CBoss::Late_Update()
{
	CEnemy::Late_Update();
}

void CBoss::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	HBRUSH hNewBrush = CreateSolidBrush(RGB(0xff, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
	Rectangle(hDC, 0, 20, m_iHp*2.5, 30);
	SelectObject(hDC, hOldBrush); // 기존에 사용하던것(Newpen)을 리턴함  
	DeleteObject(hNewBrush);
}

void CBoss::Release()
{
}

