#pragma once
#include "EnemyA.h"

//중형비행기 --> x 좌표 고정, y 좌표 증가

CEnemyA::CEnemyA() {
	memset(&m_tObjInfo, 0, sizeof(m_tObjInfo));
	x1 = 250; y1 = 100; h1 = 20; v1 = 40;
}

CEnemyA::~CEnemyA() { Release(); }

void CEnemyA::Initialize()  {
	m_tObjInfo.Set_INFO(x1, y1, h1, v1);
	m_fSpeed = 3.f;
}

int CEnemyA::Update()  {

	if (m_bDead) { return OBJ_DEAD; }

	m_tObjInfo.fX += m_fSpeed;
	__super::Update_Pos();
	return OBJ_NOEVENT;
}

void CEnemyA::Late_Update()  { }

void CEnemyA::Render(HDC hDC)  {
	
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CEnemyA::Release() {}
