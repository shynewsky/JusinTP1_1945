#pragma once
#include "pch.h"
#include "Windows.h"
#include "Enemy.h"

//중형비행기 --> x 좌표 고정, y 좌표 증가, 직선이동, 총알 2발씩 발사
class CEnemyA : public CEnemy {

public:
	CEnemyA() { }
	virtual ~CEnemyA() { Release(); }

public:
	virtual void Initialize() override {
		m_eObjId = OBJ_ENEMY;
		m_iHp = 6;
		m_iMaxHp = m_iHp;
		m_tObjInfo.fCX = 20.f; // 비행기 크기
		m_tObjInfo.fCY = 40.f; // 비행기 크기
		m_fSpeed = 1.5f; // 비행기 속도
	}
	virtual int Update() override {
		if (m_bDead)
			return OBJ_DEAD;
		
		m_tObjInfo.fY += m_fSpeed; // 이동
		Create_Bullet_Normal();

		__super::Update_Pos();
		return OBJ_NOEVENT; // 0
	}
	virtual void Late_Update() override { CEnemy::Late_Update(); }
	virtual void Release() override {}
};