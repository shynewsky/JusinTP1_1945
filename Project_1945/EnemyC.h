#pragma once
#include "pch.h"
#include "Windows.h"
#include "Enemy.h"

//대형비행기 --> x 좌표 고정, y 좌표 증가, 크기변동
class CEnemyC : public CEnemy {

public:
	CEnemyC() { }
	virtual ~CEnemyC() { Release(); }

public:
	virtual void Initialize() override {
		m_eObjId = OBJ_ENEMY;
		m_iHp = 10;
		m_iMaxHp = m_iHp;
		m_tObjInfo.fCX = 30.f; // 비행기 크기
		m_tObjInfo.fCY = 40.f; // 비행기 크기
		m_fSpeed = 0.7f; // 비행기 속도
	}
	virtual int Update() override {
		if (m_bDead)
			return OBJ_DEAD;

		m_tObjInfo.fY += m_fSpeed; // 이동

		if (m_tObjInfo.fY >= 80) { // 특정위치에서 크기 커짐
			if (m_tObjInfo.fCX < 60) {
				m_tObjInfo.fCX += 2;
				m_tObjInfo.fCY += 3;
			}
			else
			{
				Create_Bullet_Normal();
			}
		} 
		__super::Update_Pos();
		return OBJ_NOEVENT;
	}
	virtual void Late_Update() override { CEnemy::Late_Update(); }
	virtual void Release() override {}
};