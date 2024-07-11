#pragma once
#include "pch.h"
#include "Windows.h"
#include "Enemy.h"

//폭탄 --> x 좌표 고정, y 좌표 증가, 직선이동, 터질때 전방 원형으로 폭탄 발사

class CEnemyB : public CEnemy {

public:
	CEnemyB() { }
	virtual ~CEnemyB() { Release(); }

public:
	virtual void Initialize() override {
		m_eObjId = OBJ_ENEMY;
		m_iHp = 10;
		m_iMaxHp = m_iHp;
		m_tObjInfo.fCX = 20.f; // 비행기 크기
		m_tObjInfo.fCY = 40.f; // 비행기 크기
		m_fSpeed = 1.f; // 비행기 속도
	}
	virtual int Update() override {
		if (m_bDead)
			return OBJ_DEAD;

		m_tObjInfo.fY += m_fSpeed; // 이동
		Create_Bullet_Normal();

		__super::Update_Pos();
		return OBJ_NOEVENT;
	}
	virtual void Late_Update() override { CEnemy::Late_Update(); }
	virtual void Render(HDC hDC) override
	{
		HBRUSH hNewBrush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);

		Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

		SelectObject(hDC, hOldBrush); // 기존에 사용하던것(Newpen)을 리턴함  
		DeleteObject(hNewBrush);
	}
	virtual void Release() override {}
};