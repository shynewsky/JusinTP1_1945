#pragma once
#include "Obj.h"
#include "pch.h"
#include "Enemy.h"

//소형비행기 --> 궤도를 따라 움직임, 한번에 5개씩, 총알 발사 안함

class CEnemyE : public CEnemy {

private :
	// 이동경로를 공전느낌으로?
	float a; // 공전 중점의 x 좌표
	float b; // 공전 중점의 y 좌표
	float fDistance; // 공전 반지름
	float fAngle; // 공전 각도
public:
	CEnemyE() : a(-100), b(300), fDistance(200), fAngle(180.f) { }
	virtual ~CEnemyE() { Release(); }

public:
	virtual void Initialize() override {
		m_eObjId = OBJ_ENEMY;
		m_iHp = 5;
 		m_iMaxHp = m_iHp;
		m_tObjInfo.fCX = 40.f; // 비행기 크기
		m_tObjInfo.fCY = 20.f; // 비행기 크기
		m_fSpeed = 2.f; // 비행기 속도(각속도)
	}

	virtual int Update() override {
		if (m_bDead)
			return OBJ_DEAD;

		fAngle += m_fSpeed; // 일정한 속도로 공전

		// 쉴드의 원점은 공전 중심점을 삼각함수하여 구한다
		m_tObjInfo.fX = a + fDistance * cos(fAngle * (3.14 / 180.f));
		m_tObjInfo.fY = b - fDistance * sin(fAngle * (3.14 / 180.f));

		__super::Update_Pos();
		return OBJ_NOEVENT;
	}
	virtual void Late_Update() override { CEnemy::Late_Update(); }
	virtual void Release() override {}
};