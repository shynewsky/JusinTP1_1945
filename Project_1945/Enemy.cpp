#include "pch.h"
#include "Enemy.h"

void		CEnemy::Initialize()
{
}

int			CEnemy::Update()
{	
	return 0;
}

void		CEnemy::Late_Update()
{
	// 아래로 나가버리면 삭제
	if (m_tRect.top > WINCY)
	{
		m_bDead = true;
	}

	if (m_iHp <= 0)
	{
		m_Score = m_iMaxHp * 10;
		m_bDead = true;
	}
}

void		CEnemy::Render(HDC hDC)
{
	HBRUSH hNewBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, hOldBrush); // 기존에 사용하던것(Newpen)을 리턴함  
	DeleteObject(hNewBrush);
}

void		CEnemy::Release()
{
}

void		CEnemy::Create_Bullet_Normal() {

	if (dwTime + 1500 < GetTickCount()) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::CreateObj(m_tObjInfo.fX, m_tObjInfo.fY)); // 적의 위치에 생성
		static_cast<CBullet*>(m_pBulletList->back())->SetEnemyBullet(); // 일발 총알로 생성
		dwTime = GetTickCount();
	}
}

void		CEnemy::Create_Bullet_Follow() {

	if (dwTime + 1500 < GetTickCount()) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::CreateObj(m_tObjInfo.fX, m_tObjInfo.fY)); // 적의 위치에 생성
		static_cast<CBullet*>(m_pBulletList->back())->SetTarget(m_pTarget); // 플레이어 위치 가져오기
		static_cast<CBullet*>(m_pBulletList->back())->Set_Identity(false);
		static_cast<CBullet*>(m_pBulletList->back())->SetFollowBullet(); // 일발 총알로 생성
		dwTime = GetTickCount();
	}
}

void		CEnemy::Create_Bullet_Boss()
{
	DWORD bossBulletTime = GetTickCount();

	if (dwTime + 400 < GetTickCount()) {
	
		int r = rand() % 8 + 1;
		for (int i = 270; i <= 360; i += r)
		{
			m_pBulletList->push_back(CAbstractFactory<CBullet>::CreateObj(m_tObjInfo.fX, m_tObjInfo.fY)); // 적의 위치에 생성
			static_cast<CBullet*>(m_pBulletList->back())->SetBossBullet((float)i);
			dwTime = GetTickCount();
		}
		
	}
}
