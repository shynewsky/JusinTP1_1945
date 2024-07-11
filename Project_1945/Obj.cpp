#include "pch.h"
#include "Obj.h"

CObj::CObj() :m_fSpeed(0.f), m_bDead(false), m_eObjId(OBJ_END), m_pTarget(nullptr)
{
	ZeroMemory(&m_tObjInfo, sizeof(OBJINFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}

void		CObj::Update_Pos()
{
	m_tRect.left = long(m_tObjInfo.fX - (m_tObjInfo.fCX * 0.5f));
	m_tRect.top = long(m_tObjInfo.fY - (m_tObjInfo.fCY * 0.5f));
	m_tRect.right = long(m_tObjInfo.fX + (m_tObjInfo.fCX * 0.5f));
	m_tRect.bottom = long(m_tObjInfo.fY + (m_tObjInfo.fCY * 0.5f));
}
